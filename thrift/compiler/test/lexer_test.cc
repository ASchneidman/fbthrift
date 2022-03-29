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

#include <folly/portability/GTest.h>
#include <thrift/compiler/parse/lexer.h>
#include <thrift/compiler/parse/parsing_driver.h>

using namespace apache::thrift::compiler;

class LexerTest : public testing::Test {
 public:
  diagnostic_context diag_ctx;
  parsing_driver driver;

  lexer make_lexer(const std::string& input) {
    return lexer::from_string(driver, "", input);
  }

  LexerTest() : diag_ctx([](diagnostic) {}), driver(diag_ctx, "", {}) {
    driver.mode = parsing_mode::PROGRAM;
  }
};

TEST_F(LexerTest, move) {
  auto lexer = make_lexer("42");
  auto moved_lexer = std::move(lexer);
  auto token = moved_lexer.get_next_token();
  EXPECT_EQ(token.token(), yy::parser::token::tok_int_constant);
}

TEST_F(LexerTest, eof) {
  auto lexer = make_lexer("");
  auto token = lexer.get_next_token();
  EXPECT_EQ(token.token(), yy::parser::token::tok_eof);
}

TEST_F(LexerTest, identifier) {
  auto lexer = make_lexer("foo _ bar42 baz.");
  const std::string values[] = {"foo", "_", "bar42", "baz."};
  for (auto value : values) {
    auto token = lexer.get_next_token();
    EXPECT_EQ(token.token(), yy::parser::token::tok_identifier);
    EXPECT_EQ(token.value.as<std::string>(), value);
  }
}

TEST_F(LexerTest, keywords) {
  auto lexer = make_lexer("double include string");
  const yy::parser::token::yytokentype types[] = {
      yy::parser::token::tok_double,
      yy::parser::token::tok_include,
      yy::parser::token::tok_string};
  for (auto type : types) {
    auto token = lexer.get_next_token();
    EXPECT_EQ(token.token(), type);
  }
}

TEST_F(LexerTest, int_constant) {
  auto lexer = make_lexer("42 0b100 0B010 0777 0xdeadbeef 0XCAFE");
  const uint64_t values[] = {42, 0b100, 0B010, 0777, 0xdeadbeef, 0XCAFE};
  for (auto value : values) {
    auto token = lexer.get_next_token();
    EXPECT_EQ(token.token(), yy::parser::token::tok_int_constant);
    EXPECT_EQ(token.value.as<uint64_t>(), value);
  }
}

TEST_F(LexerTest, float_constant) {
  auto lexer = make_lexer("3.14 1e23 1.2E+34 0.0 .4e-2");
  const double values[] = {3.14, 1e23, 1.2E+34, 0.0, .4e-2};
  for (auto value : values) {
    auto token = lexer.get_next_token();
    EXPECT_EQ(token.token(), yy::parser::token::tok_dub_constant);
    EXPECT_EQ(token.value.as<double>(), value);
  }
}

TEST_F(LexerTest, string_literal) {
  auto lexer = make_lexer("\"foo\" 'bar' \"multi\nline\nstring\"");
  const std::string values[] = {"foo", "bar", "multi\nline\nstring"};
  for (auto value : values) {
    auto token = lexer.get_next_token();
    EXPECT_EQ(token.token(), yy::parser::token::tok_literal);
    EXPECT_EQ(token.value.as<std::string>(), value);
  }
}

TEST_F(LexerTest, whitespace) {
  auto lexer = make_lexer("\t\r\n end");
  auto token = lexer.get_next_token();
  EXPECT_EQ(token.token(), yy::parser::token::tok_identifier);
}

TEST_F(LexerTest, block_comment) {
  auto lexer = make_lexer(R"(
      /*******/
      /*
      Block
      comment
      */
      end
      )");
  auto token = lexer.get_next_token();
  EXPECT_EQ(token.token(), yy::parser::token::tok_identifier);
}

TEST_F(LexerTest, block_doc_comment) {
  auto lexer = make_lexer(R"(
        /** Block comment */
        42
      )");
  auto token = lexer.get_next_token();
  EXPECT_EQ(token.token(), yy::parser::token::tok_int_constant);
  EXPECT_EQ(*driver.doctext, "Block comment\n");
}

TEST_F(LexerTest, line_doc_comment) {
  auto lexer = make_lexer(R"(
        /// Multi-
        /// line
        /// comment
        42
      )");
  auto token = lexer.get_next_token();
  EXPECT_EQ(token.token(), yy::parser::token::tok_int_constant);
}

TEST_F(LexerTest, inline_doc_comment) {
  auto lexer = make_lexer(R"(
        ///< Multi-
        ///< line
        ///< comment
      )");
  auto token = lexer.get_next_token();
  EXPECT_EQ(token.token(), yy::parser::token::tok_inline_doc);
}
