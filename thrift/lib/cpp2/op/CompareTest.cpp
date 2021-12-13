/*
 * Copyright (c) Facebook, Inc. and its affiliates.
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

#include <array>

#include <thrift/lib/cpp2/op/Compare.h>

#include <folly/portability/GTest.h>
#include <thrift/conformance/if/gen-cpp2/object_types.h>
#include <thrift/lib/cpp2/protocol/test/gen-cpp2/Module_types_custom_protocol.h>

namespace apache::thrift::op {
namespace {
using conformance::Value;

TEST(ThriftOpTest, Double) {
  // 1 is equal and identical to itself.
  EXPECT_TRUE(equal<type::double_t>(1.0, 1.0));
  EXPECT_TRUE(identical<type::double_t>(1.0, 1.0));

  // 1 is neither equal or identical to 2.
  EXPECT_FALSE(equal<type::double_t>(1.0, 2.0));
  EXPECT_FALSE(identical<type::double_t>(1.0, 2.0));

  // -0 is equal to, but not identical to 0.
  EXPECT_TRUE(equal<type::double_t>(-0.0, +0.0));
  EXPECT_FALSE(identical<type::double_t>(-0.0, +0.0));

  // NaN is identical to, but not equal to itself.
  EXPECT_FALSE(equal<type::double_t>(
      std::numeric_limits<double>::quiet_NaN(),
      std::numeric_limits<double>::quiet_NaN()));
  EXPECT_TRUE(identical<type::double_t>(
      std::numeric_limits<double>::quiet_NaN(),
      std::numeric_limits<double>::quiet_NaN()));
}

TEST(ThriftOpTest, Float) {
  // 1 is equal and identical to itself.
  EXPECT_TRUE(equal<type::float_t>(1.0f, 1.0f));
  EXPECT_TRUE(identical<type::float_t>(1.0f, 1.0f));

  // 1 is neither equal or identical to 2.
  EXPECT_FALSE(equal<type::float_t>(1.0f, 2.0f));
  EXPECT_FALSE(identical<type::float_t>(1.0f, 2.0f));

  // -0 is equal to, but not identical to 0.
  EXPECT_TRUE(equal<type::float_t>(-0.0f, +0.0f));
  EXPECT_FALSE(identical<type::float_t>(-0.0f, +0.0f));

  // NaN is identical to, but not equal to itself.
  EXPECT_FALSE(equal<type::float_t>(
      std::numeric_limits<float>::quiet_NaN(),
      std::numeric_limits<float>::quiet_NaN()));
  EXPECT_TRUE(identical<type::float_t>(
      std::numeric_limits<float>::quiet_NaN(),
      std::numeric_limits<float>::quiet_NaN()));
}

TEST(ThriftOpTest, StructWithFloat) {
  Value lhs;
  Value rhs;
  EqualTo<type::struct_t<Value>> equal;
  IdenticalTo<type::struct_t<Value>> identical;

  lhs.floatValue_ref().ensure() = std::numeric_limits<float>::quiet_NaN();
  rhs.floatValue_ref().ensure() = std::numeric_limits<float>::quiet_NaN();
  EXPECT_FALSE(equal(lhs, rhs));
  EXPECT_FALSE(identical(lhs, rhs)); // Should be true!

  lhs.floatValue_ref().ensure() = -0.0f;
  rhs.floatValue_ref().ensure() = +0.0f;
  EXPECT_TRUE(equal(lhs, rhs));
  EXPECT_TRUE(identical(lhs, rhs)); // Should be false!
}

TEST(ThriftOpTest, ListWithDouble) {
  EqualTo<type::list<type::double_t>> equal;
  IdenticalTo<type::list<type::double_t>> identical;

  EXPECT_FALSE(equal(
      {1, std::numeric_limits<float>::quiet_NaN()},
      {1, std::numeric_limits<float>::quiet_NaN()}));
  EXPECT_TRUE(identical(
      {1, std::numeric_limits<float>::quiet_NaN()},
      {1, std::numeric_limits<float>::quiet_NaN()}));

  EXPECT_TRUE(equal({-0.0, 2.0}, {+0.0, 2.0}));
  EXPECT_FALSE(identical({-0.0, 2.0}, {+0.0, 2.0}));
}

TEST(ThriftOpTest, SetWithDouble) {
  EqualTo<type::set<type::double_t>> equal;
  IdenticalTo<type::set<type::double_t>> identical;

  // Note: NaN in a set is undefined behavior.

  EXPECT_TRUE(equal({-0.0, 2.0}, {+0.0, 2.0}));
  EXPECT_TRUE(identical({-0.0, 2.0}, {+0.0, 2.0})); // Should be false!
}

TEST(ThriftOpTest, MapWithDouble) {
  EqualTo<type::map<type::double_t, type::float_t>> equal;
  IdenticalTo<type::map<type::double_t, type::float_t>> identical;

  // Note: NaN in a map keys is undefined behavior.
  EXPECT_FALSE(equal(
      {{1, std::numeric_limits<float>::quiet_NaN()}},
      {{1, std::numeric_limits<float>::quiet_NaN()}}));
  EXPECT_FALSE(identical(
      {{1, std::numeric_limits<float>::quiet_NaN()}},
      {{1, std::numeric_limits<float>::quiet_NaN()}})); // Should be true!

  EXPECT_TRUE(equal({{-0.0, 2.0}}, {{+0.0, 2.0}}));
  EXPECT_TRUE(identical({{-0.0, 2.0}}, {{+0.0, 2.0}})); // Should be false!
  EXPECT_TRUE(equal({{2.0, +0.0}}, {{2.0, -0.0}}));
  EXPECT_TRUE(identical({{2.0, +0.0}}, {{2.0, -0.0}})); // Should be false!
  EXPECT_TRUE(equal({{-0.0, +0.0}}, {{+0.0, -0.0}}));
  EXPECT_TRUE(identical({{-0.0, +0.0}}, {{+0.0, -0.0}})); // Should be false!
}

} // namespace
} // namespace apache::thrift::op
