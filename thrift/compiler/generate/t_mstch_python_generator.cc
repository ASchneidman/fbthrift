/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <algorithm>
#include <iterator>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/filesystem.hpp>

#include <thrift/compiler/ast/t_service.h>
#include <thrift/compiler/generate/common.h>
#include <thrift/compiler/generate/t_mstch_generator.h>
#include <thrift/compiler/generate/t_mstch_objects.h>
#include <thrift/compiler/lib/cpp2/util.h>
#include <thrift/compiler/lib/py3/util.h>

namespace apache {
namespace thrift {
namespace compiler {

namespace {

std::vector<std::string> get_py3_namespace(const t_program* prog) {
  return split_namespace(prog->get_namespace("py3"));
}

std::string get_py3_namespace_with_name_and_prefix(
    const t_program* prog, const std::string& prefix) {
  std::ostringstream ss;
  if (!prefix.empty()) {
    ss << prefix << ".";
  }
  for (const auto& name : split_namespace(prog->get_namespace("py3"))) {
    ss << name << ".";
  }
  ss << prog->name();
  return ss.str();
}

bool is_type_iobuf(const std::string& name) {
  return name == "folly::IOBuf" || name == "std::unique_ptr<folly::IOBuf>";
}

bool is_func_supported(const t_function* func) {
  return !func->returns_stream() && !func->returns_sink() &&
      !func->get_returntype()->is_service();
}

const t_const* find_structured_adapter_annotation(const t_named& node) {
  return node.find_structured_annotation_or_null(
      "facebook.com/thrift/annotation/python/Adapter");
}

const std::string get_annotation_property(
    const t_const* annotation, const std::string& key) {
  if (annotation) {
    for (const auto& item : annotation->value()->get_map()) {
      if (item.first->get_string() == key) {
        return item.second->get_string();
      }
    }
  }
  return "";
}

const std::string extract_module_path(const std::string& fully_qualified_name) {
  auto tokens = split_namespace(fully_qualified_name);
  if (tokens.size() <= 1) {
    return "";
  }
  tokens.pop_back();
  return boost::algorithm::join(tokens, ".");
}

class mstch_python_type : public mstch_type {
 public:
  mstch_python_type(
      const t_type* type,
      std::shared_ptr<const mstch_generators> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      const t_program* prog)
      : mstch_type(type, std::move(generators), std::move(cache), pos),
        prog_{prog} {
    register_methods(
        this,
        {
            {"type:module_path", &mstch_python_type::module_path},
            {"type:program_name", &mstch_python_type::program_name},
            {"type:metadata_path", &mstch_python_type::metadata_path},
            {"type:py3_namespace", &mstch_python_type::py3_namespace},
            {"type:need_module_path?", &mstch_python_type::need_module_path},
            {"type:external_program?", &mstch_python_type::is_external_program},
            {"type:integer?", &mstch_python_type::is_integer},
            {"type:iobuf?", &mstch_python_type::is_iobuf},
        });
  }

  mstch::node module_path() {
    return get_py3_namespace_with_name_and_prefix(
               get_type_program(), get_option("root_module_prefix")) +
        ".lite_types";
  }

  mstch::node program_name() { return get_type_program()->name(); }

  mstch::node metadata_path() {
    return get_py3_namespace_with_name_and_prefix(
               get_type_program(), get_option("root_module_prefix")) +
        ".lite_metadata";
  }

  mstch::node py3_namespace() {
    std::ostringstream ss;
    for (const auto& path : get_py3_namespace(get_type_program())) {
      ss << path << ".";
    }
    return ss.str();
  }

  mstch::node need_module_path() {
    if (!has_option("is_types_file")) {
      return true;
    }
    if (const t_program* prog = type_->program()) {
      if (prog != prog_) {
        return true;
      }
    }
    return false;
  }

  mstch::node is_external_program() {
    auto p = type_->program();
    return p && p != prog_;
  }

  mstch::node is_integer() { return type_->is_any_int() || type_->is_byte(); }

  // Supporting legacy py3 cpp.type iobuf declaration here
  mstch::node is_iobuf() {
    return type_->has_annotation("py3.iobuf") ||
        is_type_iobuf(type_->get_annotation("cpp2.type")) ||
        is_type_iobuf(type_->get_annotation("cpp.type"));
  }

 protected:
  const t_program* get_type_program() const {
    if (const t_program* p = type_->program()) {
      return p;
    }
    return prog_;
  }

  const t_program* prog_;
};

class mstch_python_const_value : public mstch_const_value {
 public:
  mstch_python_const_value(
      t_const_value const* const_value,
      t_const const* current_const,
      t_type const* expected_type,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t index)
      : mstch_const_value(
            const_value,
            current_const,
            expected_type,
            std::move(generators),
            std::move(cache),
            pos,
            index) {
    register_methods(
        this,
        {
            {"value:py3_string_value", &mstch_python_const_value::string_value},
            {"value:py3_string?", &mstch_python_const_value::is_string},
            {"value:py3_binary?", &mstch_python_const_value::is_binary},
            {"value:const_enum_type",
             &mstch_python_const_value::const_enum_type},
            {"value:value_for_bool?",
             &mstch_python_const_value::value_for_bool},
            {"value:value_for_floating_point?",
             &mstch_python_const_value::value_for_floating_point},
            {"value:list_elem_type", &mstch_python_const_value::list_elem_type},
            {"value:value_for_set?", &mstch_python_const_value::value_for_set},
            {"value:map_key_type", &mstch_python_const_value::map_key_type},
            {"value:map_val_type", &mstch_python_const_value::map_val_type},
        });
  }
  mstch::node is_string() {
    auto& ttype = const_value_->ttype();
    return type_ == cv::CV_STRING && ttype &&
        ttype->get_true_type()->is_string();
  }

  mstch::node is_binary() {
    auto& ttype = const_value_->ttype();
    return type_ == cv::CV_STRING && ttype &&
        ttype->get_true_type()->is_binary();
  }

  mstch::node const_enum_type() {
    if (!const_value_->ttype() || type_ != cv::CV_INTEGER ||
        !const_value_->is_enum()) {
      return {};
    }
    const auto* type = const_value_->ttype()->get_true_type();
    if (type->is_enum()) {
      return generators_->type_generator_->generate(type, generators_, cache_);
    }
    return {};
  }

  mstch::node value_for_bool() {
    if (auto ttype = const_value_->ttype()) {
      return ttype->get_true_type()->is_bool();
    }
    return false;
  }

  mstch::node value_for_floating_point() {
    if (auto ttype = const_value_->ttype()) {
      return ttype->get_true_type()->is_floating_point();
    }
    return false;
  }

  mstch::node string_value() {
    if (type_ != cv::CV_STRING) {
      return mstch::node();
    }
    std::string string_val = const_value_->get_string();
    if (string_val.find('\n') == std::string::npos) {
      if (string_val.find('"') == std::string::npos) {
        return "\"" + string_val + "\"";
      }
      if (string_val.find('\'') == std::string::npos) {
        return "'" + string_val + "'";
      }
    }
    const auto& front = string_val.front();
    const auto& back = string_val.back();

    if (front != '"' && back != '"') {
      return "\"\"\"" + string_val + "\"\"\"";
    }
    if (front != '\'' && back != '\'') {
      return "'''" + string_val + "'''";
    }
    if (front == '"') { // and back = '\''
      string_val.pop_back(); // remove the last '\''
      return "'''" + string_val + "'''\"'\"";
    }
    // the only possible case left: back = '"' and front = '\''
    string_val.pop_back(); // remove the last '"'
    return "\"\"\"" + string_val + "\"\"\"'\"'";
  }

  mstch::node list_elem_type() {
    if (auto ttype = const_value_->ttype()) {
      const auto* type = ttype->get_true_type();
      const t_type* elem_type = nullptr;
      if (type->is_list()) {
        elem_type = dynamic_cast<const t_list*>(type)->get_elem_type();
      } else if (type->is_set()) {
        elem_type = dynamic_cast<const t_set*>(type)->get_elem_type();
      } else {
        return {};
      }
      return generators_->type_generator_->generate(
          elem_type, generators_, cache_, pos_);
    }
    return {};
  }

  mstch::node value_for_set() {
    if (auto ttype = const_value_->ttype()) {
      return ttype->get_true_type()->is_set();
    }
    return false;
  }

  mstch::node map_key_type() {
    if (auto ttype = const_value_->ttype()) {
      const auto* type = ttype->get_true_type();
      if (type->is_map()) {
        return generators_->type_generator_->generate(
            dynamic_cast<const t_map*>(type)->get_key_type(),
            generators_,
            cache_,
            pos_);
      }
    }
    return {};
  }

  mstch::node map_val_type() {
    if (auto ttype = const_value_->ttype()) {
      const auto* type = ttype->get_true_type();
      if (type->is_map()) {
        return generators_->type_generator_->generate(
            dynamic_cast<const t_map*>(type)->get_val_type(),
            generators_,
            cache_,
            pos_);
      }
    }
    return {};
  }
};

class type_python_generator : public type_generator {
 public:
  explicit type_python_generator(const t_program* prog) : prog_{prog} {}
  std::shared_ptr<mstch_base> generate(
      const t_type* type,
      std::shared_ptr<const mstch_generators> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t /*index*/) const override {
    auto true_type = type->get_true_type();
    return std::make_shared<mstch_python_type>(
        true_type, generators, cache, pos, prog_);
  }

 protected:
  const t_program* prog_;
};

class mstch_python_program : public mstch_program {
 public:
  mstch_python_program(
      const t_program* program,
      std::shared_ptr<const mstch_generators> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos)
      : mstch_program{program, std::move(generators), std::move(cache), pos} {
    register_methods(
        this,
        {
            {"program:module_path", &mstch_python_program::module_path},
            {"program:is_types_file?", &mstch_python_program::is_types_file},
            {"program:include_namespaces",
             &mstch_python_program::include_namespaces},
            {"program:base_library_package",
             &mstch_python_program::base_library_package},
            {"program:root_module_prefix",
             &mstch_python_program::root_module_prefix},
            {"program:adapter_modules", &mstch_python_program::adapter_modules},
            {"program:adapter_type_hint_modules",
             &mstch_python_program::adapter_type_hint_modules},
        });
    gather_included_program_namespaces();
    visit_types_for_services_and_interactions();
    visit_types_for_objects();
    visit_types_for_constants();
    visit_types_for_typedefs();
    visit_types_for_mixin_fields();
    visit_types_for_adapters();
  }

  mstch::node is_types_file() { return has_option("is_types_file"); }

  mstch::node include_namespaces() {
    std::vector<const Namespace*> namespaces;
    for (const auto& it : include_namespaces_) {
      namespaces.push_back(&it.second);
    }
    std::sort(
        namespaces.begin(), namespaces.end(), [](const auto* m, const auto* n) {
          return m->ns < n->ns;
        });
    mstch::array a;
    for (const auto& it : namespaces) {
      a.push_back(mstch::map{
          {"included_module_path", it->ns},
          {"has_services?", it->has_services},
          {"has_types?", it->has_types}});
    }
    return a;
  }

  mstch::node module_path() {
    return get_py3_namespace_with_name_and_prefix(
        program_, get_option("root_module_prefix"));
  }

  mstch::node base_library_package() {
    auto option = get_option("base_library_package");
    return option.empty() ? "thrift.python" : option;
  }

  mstch::node root_module_prefix() {
    auto prefix = get_option("root_module_prefix");
    return prefix.empty() ? "" : prefix + ".";
  }

  mstch::node adapter_modules() { return module_path_array(adapter_modules_); }

  mstch::node adapter_type_hint_modules() {
    return module_path_array(adapter_type_hint_modules_);
  }

 protected:
  struct Namespace {
    std::string ns;
    bool has_services;
    bool has_types;
  };

  void gather_included_program_namespaces() {
    for (const t_program* included_program :
         program_->get_included_programs()) {
      bool has_types =
          !(included_program->objects().empty() &&
            included_program->enums().empty() &&
            included_program->typedefs().empty() &&
            included_program->consts().empty());
      include_namespaces_[included_program->path()] = Namespace{
          get_py3_namespace_with_name_and_prefix(
              included_program, get_option("root_module_prefix")),
          !included_program->services().empty(),
          has_types,
      };
    }
  }

  void add_typedef_namespace(const t_type* type) {
    auto prog = type->program();
    if (prog && prog != program_) {
      const auto& path = prog->path();
      if (include_namespaces_.find(path) != include_namespaces_.end()) {
        return;
      }
      auto ns = Namespace();
      ns.ns = get_py3_namespace_with_name_and_prefix(
          prog, get_option("root_module_prefix"));
      ns.has_services = false;
      ns.has_types = true;
      include_namespaces_[path] = std::move(ns);
    }
  }

  void visit_type_single_service(const t_service* service) {
    for (const auto& function : service->functions()) {
      for (const auto& field : function.get_paramlist()->fields()) {
        visit_type(field.get_type());
      }
      for (const auto& field : function.get_stream_xceptions()->fields()) {
        visit_type(field.get_type());
      }
      visit_type(function.get_returntype());
    }
  }

  void visit_types_for_services_and_interactions() {
    for (const auto* service : program_->services()) {
      visit_type_single_service(service);
    }
    for (const auto* interaction : program_->interactions()) {
      visit_type_single_service(interaction);
    }
  }

  void visit_types_for_objects() {
    for (const auto& object : program_->objects()) {
      for (auto&& field : object->fields()) {
        visit_type(field.get_type());
      }
    }
  }

  void visit_types_for_constants() {
    for (const auto& constant : program_->consts()) {
      visit_type(constant->get_type());
    }
  }

  void visit_types_for_typedefs() {
    for (const auto typedef_def : program_->typedefs()) {
      visit_type(typedef_def->get_type());
    }
  }

  void visit_types_for_mixin_fields() {
    for (const auto& strct : program_->structs()) {
      for (const auto& m : cpp2::get_mixins_and_members(*strct)) {
        visit_type(m.member->get_type());
      }
    }
  }

  void visit_types_for_adapters() {
    for (const auto& strct : program_->structs()) {
      for (const auto& field : strct->fields()) {
        if (auto annotation = find_structured_adapter_annotation(field)) {
          extract_module_and_insert_to(
              get_annotation_property(annotation, "name"), adapter_modules_);
          extract_module_and_insert_to(
              get_annotation_property(annotation, "typeHint"),
              adapter_type_hint_modules_);
        }
      }
    }
  }

  void extract_module_and_insert_to(
      const std::string& name, std::unordered_set<std::string>& modules) {
    auto module_path = extract_module_path(name);
    if (module_path != "") {
      modules.insert(module_path);
    }
  }

  enum TypeDef { NoTypedef, HasTypedef };

  void visit_type(const t_type* orig_type) {
    return visit_type_with_typedef(orig_type, TypeDef::NoTypedef);
  }

  void visit_type_with_typedef(const t_type* orig_type, TypeDef is_typedef) {
    auto true_type = orig_type->get_true_type();
    if (!seen_types_.insert(true_type).second) {
      return;
    }
    is_typedef = is_typedef == TypeDef::HasTypedef || orig_type->is_typedef()
        ? TypeDef::HasTypedef
        : TypeDef::NoTypedef;
    if (is_typedef == TypeDef::HasTypedef) {
      add_typedef_namespace(true_type);
    }
    if (true_type->is_list()) {
      visit_type_with_typedef(
          dynamic_cast<const t_list&>(*true_type).get_elem_type(), is_typedef);
    } else if (true_type->is_set()) {
      visit_type_with_typedef(
          dynamic_cast<const t_set&>(*true_type).get_elem_type(), is_typedef);
    } else if (true_type->is_map()) {
      visit_type_with_typedef(
          dynamic_cast<const t_map&>(*true_type).get_key_type(), is_typedef);
      visit_type_with_typedef(
          dynamic_cast<const t_map&>(*true_type).get_val_type(), is_typedef);
    } else if (true_type->is_streamresponse()) {
      const t_type* resp_type =
          dynamic_cast<const t_stream_response&>(*true_type)
              .get_first_response_type();
      const t_type* elem_type =
          dynamic_cast<const t_stream_response&>(*true_type).get_elem_type();
      if (resp_type) {
        visit_type_with_typedef(resp_type, is_typedef);
      }
      visit_type_with_typedef(elem_type, is_typedef);
    }
  }

  mstch::node module_path_array(
      const std::unordered_set<std::string>& modules) {
    mstch::array a;
    for (const auto& m : modules) {
      a.push_back(mstch::map{{"module_path", m}});
    }
    return a;
  }

  std::unordered_map<std::string, Namespace> include_namespaces_;
  std::unordered_set<const t_type*> seen_types_;
  std::unordered_set<std::string> adapter_modules_;
  std::unordered_set<std::string> adapter_type_hint_modules_;
};

class mstch_python_field : public mstch_field {
 public:
  mstch_python_field(
      const t_field* field,
      std::shared_ptr<const mstch_generators> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t index,
      field_generator_context const* field_context)
      : mstch_field(
            field,
            std::move(generators),
            std::move(cache),
            pos,
            index,
            field_context),
        py_name_{py3::get_py3_name(*field)},
        adapter_annotation_(find_structured_adapter_annotation(*field)) {
    register_methods(
        this,
        {
            {"field:py_name", &mstch_python_field::py_name},
            {"field:user_default_value",
             &mstch_python_field::user_default_value},
            {"field:has_adapter?", &mstch_python_field::has_adapter},
            {"field:adapter_name", &mstch_python_field::adapter_name},
            {"field:adapter_type_hint", &mstch_python_field::adapter_type_hint},
        });
  }

  mstch::node py_name() { return py_name_; }
  mstch::node user_default_value() {
    const t_const_value* value = field_->get_value();
    if (!value) {
      return mstch::node();
    }
    if (value->is_empty()) {
      auto true_type = field_->get_type()->get_true_type();
      if ((true_type->is_list() || true_type->is_set()) &&
          value->get_type() != t_const_value::CV_LIST) {
        const_cast<t_const_value*>(value)->set_list();
      }
      if (true_type->is_map() && value->get_type() != t_const_value::CV_MAP) {
        const_cast<t_const_value*>(value)->set_map();
      }
    }
    return generators_->const_value_generator_->generate(
        value, generators_, cache_, pos_);
  }
  mstch::node has_adapter() { return adapter_annotation_ != nullptr; }
  mstch::node adapter_name() {
    return get_annotation_property(adapter_annotation_, "name");
  }
  mstch::node adapter_type_hint() {
    return get_annotation_property(adapter_annotation_, "typeHint");
  }

 private:
  const std::string py_name_;
  const t_const* adapter_annotation_;
};

class mstch_python_struct : public mstch_struct {
 public:
  mstch_python_struct(
      const t_struct* strct,
      std::shared_ptr<const mstch_generators> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos)
      : mstch_struct(strct, std::move(generators), std::move(cache), pos) {
    register_methods(
        this,
        {
            {"struct:fields_and_mixin_fields",
             &mstch_python_struct::fields_and_mixin_fields},
            {"struct:exception_message?",
             &mstch_python_struct::has_exception_message},
            {"struct:exception_message",
             &mstch_python_struct::exception_message},
        });
  }

  mstch::node fields_and_mixin_fields() {
    std::vector<t_field const*> fields = strct_->fields().copy();
    for (auto m : cpp2::get_mixins_and_members(*strct_)) {
      fields.push_back(m.member);
    }
    return generate_fields(fields);
  }

  mstch::node has_exception_message() {
    return strct_->has_annotation("message");
  }
  mstch::node exception_message() { return strct_->get_annotation("message"); }
};

class mstch_python_enum : public mstch_enum {
 public:
  mstch_python_enum(
      const t_enum* enm,
      std::shared_ptr<const mstch_generators> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos)
      : mstch_enum(enm, std::move(generators), std::move(cache), pos) {
    register_methods(
        this,
        {
            {"enum:flags?", &mstch_python_enum::has_flags},
        });
  }

  mstch::node has_flags() { return enm_->has_annotation("py3.flags"); }
};

class mstch_python_enum_value : public mstch_enum_value {
 public:
  mstch_python_enum_value(
      const t_enum_value* enm_value,
      std::shared_ptr<const mstch_generators> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos)
      : mstch_enum_value(
            enm_value, std::move(generators), std::move(cache), pos) {
    register_methods(
        this,
        {
            {"enum_value:py_name", &mstch_python_enum_value::py_name},
        });
  }

  mstch::node py_name() { return py3::get_py3_name(*enm_value_); }
};

class program_python_generator : public program_generator {
 public:
  std::shared_ptr<mstch_base> generate(
      const t_program* program,
      std::shared_ptr<const mstch_generators> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t /*index*/) const override {
    const std::string& id = program->path();
    auto it = cache->programs_.find(id);
    if (it != cache->programs_.end()) {
      return it->second;
    }
    auto r = cache->programs_.emplace(
        id,
        std::make_shared<mstch_python_program>(
            program, generators, cache, pos));
    return r.first->second;
  }
};

class struct_python_generator : public struct_generator {
 public:
  std::shared_ptr<mstch_base> generate(
      const t_struct* strct,
      std::shared_ptr<const mstch_generators> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t /*index*/) const override {
    return std::make_shared<mstch_python_struct>(strct, generators, cache, pos);
  }
};

class mstch_python_function : public mstch_function {
 public:
  mstch_python_function(
      t_function const* function,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION const pos)
      : mstch_function(function, generators, cache, pos) {
    register_methods(
        this,
        {
            {"function:args?", &mstch_python_function::has_args},
        });
  }

  mstch::node has_args() {
    return !function_->get_paramlist()->get_members().empty();
  }

 protected:
  const std::string cppName_;
};

class function_python_generator : public function_generator {
 public:
  function_python_generator() = default;
  ~function_python_generator() override = default;
  std::shared_ptr<mstch_base> generate(
      t_function const* function,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t /*index*/) const override {
    return std::make_shared<mstch_python_function>(
        function, generators, cache, pos);
  }
};

class mstch_python_service : public mstch_service {
 public:
  mstch_python_service(
      const t_service* service,
      std::shared_ptr<const mstch_generators> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION const pos,
      const t_program* prog)
      : mstch_service(service, generators, cache, pos), prog_{prog} {
    register_methods(
        this,
        {
            {"service:module_path", &mstch_python_service::module_path},
            {"service:program_name", &mstch_python_service::program_name},
            {"service:parent_service_name",
             &mstch_python_service::parent_service_name},
            {"service:supported_functions",
             &mstch_python_service::supported_functions},
            {"service:supported_functions?",
             &mstch_python_service::has_supported_functions},
            {"service:external_program?",
             &mstch_python_service::is_external_program},
        });
  }

  mstch::node module_path() {
    return get_py3_namespace_with_name_and_prefix(
        service_->program(), get_option("root_module_prefix"));
  }

  mstch::node program_name() { return service_->program()->name(); }

  mstch::node parent_service_name() {
    return cache_->parsed_options_.at("parent_service_name");
  }

  std::vector<t_function*> get_supported_functions() {
    std::vector<t_function*> funcs;
    for (auto func : service_->get_functions()) {
      if (is_func_supported(func)) {
        funcs.push_back(func);
      }
    }
    return funcs;
  }

  mstch::node supported_functions() {
    return generate_functions(get_supported_functions());
  }

  mstch::node has_supported_functions() {
    return !get_supported_functions().empty();
  }

  mstch::node is_external_program() { return prog_ != service_->program(); }

 protected:
  const t_program* prog_;
};

class service_python_generator : public service_generator {
 public:
  explicit service_python_generator(const t_program* prog) : prog_{prog} {}
  std::shared_ptr<mstch_base> generate(
      const t_service* service,
      std::shared_ptr<const mstch_generators> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t /*index*/) const override {
    return std::make_shared<mstch_python_service>(
        service, generators, cache, pos, prog_);
  }

 protected:
  const t_program* prog_;
};

class field_python_generator : public field_generator {
 public:
  std::shared_ptr<mstch_base> generate(
      const t_field* field,
      std::shared_ptr<const mstch_generators> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t index,
      field_generator_context const* field_context) const override {
    return std::make_shared<mstch_python_field>(
        field, generators, cache, pos, index, field_context);
  }
};

class enum_python_generator : public enum_generator {
 public:
  std::shared_ptr<mstch_base> generate(
      const t_enum* enm,
      std::shared_ptr<const mstch_generators> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t /*index*/) const override {
    return std::make_shared<mstch_python_enum>(enm, generators, cache, pos);
  }
};

class enum_value_python_generator : public enum_value_generator {
 public:
  std::shared_ptr<mstch_base> generate(
      const t_enum_value* enm_value,
      std::shared_ptr<const mstch_generators> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t /*index*/) const override {
    return std::make_shared<mstch_python_enum_value>(
        enm_value, generators, cache, pos);
  }
};

class const_value_python_generator : public const_value_generator {
 public:
  const_value_python_generator() = default;
  ~const_value_python_generator() override = default;
  std::shared_ptr<mstch_base> generate(
      t_const_value const* const_value,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t index,
      t_const const* current_const,
      t_type const* expected_type) const override {
    return std::make_shared<mstch_python_const_value>(
        const_value,
        current_const,
        expected_type,
        generators,
        cache,
        pos,
        index);
  }
};

/**
 * Generator-specific validator that enforces that reserved key is
 * not used as namespace field name.
 */
class no_reserved_key_in_namespace_validator : virtual public validator {
 public:
  using validator::visit;

  bool visit(t_program* const prog) override {
    set_program(prog);
    validate(prog);
    return true;
  }

 private:
  void validate(t_program* const prog) {
    const auto& py3_namespace = prog->get_namespace("py3");
    if (py3_namespace.empty()) {
      return;
    }

    std::vector<std::string> namespace_tokens = split_namespace(py3_namespace);
    for (const auto& field_name : namespace_tokens) {
      if (get_python_reserved_names().find(field_name) !=
          get_python_reserved_names().end()) {
        std::ostringstream ss;
        ss << "Namespace '" << py3_namespace << "' contains reserved keyword '"
           << field_name << "'";
        add_error(boost::none, ss.str());
      }
    }

    std::string filepath_delimiters("\\/.");
    std::vector<std::string> fields;
    boost::split(fields, prog->path(), boost::is_any_of(filepath_delimiters));
    for (const auto& field : fields) {
      if (field == "include") {
        std::ostringstream ss;
        ss << "Path '" << prog->path()
           << "' contains reserved keyword 'include'";
        add_error(boost::none, ss.str());
      }
    }
  }
};

/**
 * Generator-specific validator that enforces "name" and "value" is not used
 * as enum member or union field names (thrift-py3)
 */
class enum_member_union_field_names_validator : virtual public validator {
 public:
  using validator::visit;

  bool visit(t_enum* enm) override {
    for (const t_enum_value* ev : enm->get_enum_values()) {
      validate(ev, ev->get_name());
    }
    return true;
  }

  bool visit(t_struct* s) override {
    if (!s->is_union()) {
      return false;
    }
    for (const t_field& f : s->fields()) {
      validate(&f, f.name());
    }
    return true;
  }

 private:
  void validate(const t_named* node, const std::string& name) {
    const auto& pyname = node->get_annotation("py3.name", &name);
    if (pyname == "name" || pyname == "value") {
      std::ostringstream ss;
      ss << "'" << pyname
         << "' should not be used as an enum/union field name in thrift-py3. "
         << "Use a different name or annotate the field with `(py3.name=\"<new_py_name>\")`";
      add_error(node->get_lineno(), ss.str());
    }
  }
};

class t_mstch_python_generator : public t_mstch_generator {
 public:
  t_mstch_python_generator(
      t_program* program,
      t_generation_context context,
      const std::map<std::string, std::string>& parsed_options,
      const std::string& /* option_string unused */)
      : t_mstch_generator(
            program, std::move(context), "python", parsed_options),
        generate_root_path_{package_to_path()} {
    out_dir_base_ = "gen-python";
    auto include_prefix = get_option("include_prefix");
    if (!include_prefix.empty()) {
      program->set_include_prefix(std::move(include_prefix));
    }
  }

  void generate_program() override {
    set_mstch_generators();
    generate_types();
    generate_metadata();
    generate_clients();
    generate_services();
  }

  void fill_validator_list(validator_list& vl) const override {
    vl.add<no_reserved_key_in_namespace_validator>();
    vl.add<enum_member_union_field_names_validator>();
  }

  enum TypesFile { IsTypesFile, NotTypesFile };

 protected:
  bool should_resolve_typedefs() const override { return true; }
  void set_mstch_generators();
  void generate_file(
      const std::string& file,
      TypesFile is_types_file,
      const boost::filesystem::path& base);
  void set_types_file(bool val);
  void generate_types();
  void generate_metadata();
  void generate_clients();
  void generate_services();
  boost::filesystem::path package_to_path();

  const boost::filesystem::path generate_root_path_;
};

} // namespace

void t_mstch_python_generator::set_mstch_generators() {
  generators_->set_program_generator(
      std::make_unique<program_python_generator>());
  generators_->set_struct_generator(
      std::make_unique<struct_python_generator>());
  generators_->set_function_generator(
      std::make_unique<function_python_generator>());
  generators_->set_service_generator(
      std::make_unique<service_python_generator>(get_program()));
  generators_->set_field_generator(std::make_unique<field_python_generator>());
  generators_->set_enum_generator(std::make_unique<enum_python_generator>());
  generators_->set_enum_value_generator(
      std::make_unique<enum_value_python_generator>());
  generators_->set_const_value_generator(
      std::make_unique<const_value_python_generator>());
  generators_->set_type_generator(
      std::make_unique<type_python_generator>(get_program()));
}

boost::filesystem::path t_mstch_python_generator::package_to_path() {
  auto package = get_program()->get_namespace("py3");
  return boost::algorithm::replace_all_copy(package, ".", "/");
}

void t_mstch_python_generator::generate_file(
    const std::string& file,
    TypesFile is_types_file,
    const boost::filesystem::path& base = {}) {
  auto program = get_program();
  const auto& name = program->name();
  if (is_types_file == IsTypesFile) {
    cache_->parsed_options_["is_types_file"] = "";
  } else {
    cache_->parsed_options_.erase("is_types_file");
  }
  auto node_ptr =
      generators_->program_generator_->generate(program, generators_, cache_);
  render_to_file(node_ptr, file, base / name / file);
}

void t_mstch_python_generator::generate_types() {
  generate_file("lite_types.py", IsTypesFile, generate_root_path_);
  generate_file("lite_types.pyi", IsTypesFile, generate_root_path_);
  generate_file("thrift_types.py", IsTypesFile, generate_root_path_);
  generate_file("thrift_types.pyi", IsTypesFile, generate_root_path_);
}

void t_mstch_python_generator::generate_metadata() {
  generate_file("lite_metadata.py", IsTypesFile, generate_root_path_);
  generate_file("thrift_metadata.py", IsTypesFile, generate_root_path_);
}

void t_mstch_python_generator::generate_clients() {
  if (get_program()->services().empty()) {
    // There is no need to generate empty / broken code for non existent
    // services.
    return;
  }

  generate_file("lite_clients.py", NotTypesFile, generate_root_path_);
  generate_file("thrift_clients.py", NotTypesFile, generate_root_path_);
}

void t_mstch_python_generator::generate_services() {
  if (get_program()->services().empty()) {
    // There is no need to generate empty / broken code for non existent
    // services.
    return;
  }
  generate_file("lite_services.py", NotTypesFile, generate_root_path_);
  generate_file("thrift_services.py", NotTypesFile, generate_root_path_);
}

THRIFT_REGISTER_GENERATOR(
    mstch_python,
    "Python",
    "    include_prefix:  Use full include paths in generated files.\n");

static t_generator_factory_impl<t_mstch_python_generator> alias(
    "mstch_py3lite",
    "Py3 Lite",
    "    include_prefix:  Use full include paths in generated files.\n");

} // namespace compiler
} // namespace thrift
} // namespace apache
