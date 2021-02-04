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

#pragma once

#include <atomic>
#include <mutex>
#include <type_traits>

#include <folly/Optional.h>
#include <folly/SharedMutex.h>
#include <folly/experimental/observer/SimpleObservable.h>
#include <folly/synchronization/DelayedInit.h>

namespace apache {
namespace thrift {

/*
 * ServerAttribute provides a mechanism for setting values which have varying
 * precedence depending on who set it. The resolved value (`.get()`)
 * prioritizes the value in the following order, falling back to the next one
 * if the value is unset:
 *   1. explicit application override
 *   2. baseline from configuration mechanism
 *   3. default provided in constructor
 */

// source of a server's attribute, precedence takes place in descending order
// (APP will override CONF). see comment on ServerAttribute to learn more
enum class AttributeSource : uint32_t {
  OVERRIDE, // when set directly in application code
  BASELINE, // e.g., may come from external configuration mechanism
};

/**
 * A thread-safe ServerAttribute which uses folly::observer internally but reads
 * are cached via `folly::observer::AtomicObserver`.
 */
template <typename T>
struct ServerAttributeAtomic;

/**
 * A thread-safe ServerAttribute which uses folly::observer internally but reads
 * are cached via `folly::observer::TLObserver`.
 */
template <typename T>
struct ServerAttributeThreadLocal;

/**
 * A thread-safe ServerAttribute of suitable type.
 */
template <typename T>
using ServerAttribute = std::conditional_t<
    sizeof(T) <= sizeof(std::uint64_t) && std::is_trivially_copyable<T>::value,
    ServerAttributeAtomic<T>,
    ServerAttributeThreadLocal<T>>;

namespace detail {

template <typename T>
struct ServerAttributeRawValues {
  T baseline_;
  T override_;

  template <typename U, typename V>
  ServerAttributeRawValues(U&& baseline, V&& override)
      : baseline_(std::forward<U>(baseline)),
        override_(std::forward<V>(override)) {}

  T& choose(AttributeSource source) {
    return source == AttributeSource::OVERRIDE ? override_ : baseline_;
  }
};

template <typename T>
T& mergeServerAttributeRawValues(
    folly::Optional<T>& override,
    folly::Optional<T>& baseline,
    T& defaultValue) {
  return override ? *override : baseline ? *baseline : defaultValue;
}

template <typename T>
struct ServerAttributeObservable {
  explicit ServerAttributeObservable(T defaultValue)
      : ServerAttributeObservable(
            folly::observer::makeStaticObserver<T>(std::move(defaultValue))) {}
  explicit ServerAttributeObservable(folly::observer::Observer<T> defaultValue)
      : default_(std::move(defaultValue)) {}

  T get() const {
    return **getObserver();
  }

  const folly::observer::Observer<T>& getObserver() const {
    return mergedObserver_.try_emplace_with([&] {
      return folly::observer::makeObserver(
          [overrideObserver = rawValues_.override_.getObserver(),
           baselineObserver = rawValues_.baseline_.getObserver(),
           defaultObserver =
               std::move(default_)]() mutable -> std::shared_ptr<T> {
            folly::Optional<folly::observer::Observer<T>> override =
                **overrideObserver;
            folly::Optional<folly::observer::Observer<T>> baseline =
                **baselineObserver;
            return std::make_shared<T>(
                **apache::thrift::detail::mergeServerAttributeRawValues(
                    override, baseline, defaultObserver));
          });
    });
  }

  void set(folly::observer::Observer<T> value, AttributeSource source) {
    rawValues_.choose(source).setValue(folly::Optional{std::move(value)});
    if (source == AttributeSource::OVERRIDE) {
      // For backward compatibility reasons, we need to block until the observer
      // value is updated. This ensures that reads always produce the latest
      // value after a write from the writer thread. We need to be careful and
      // only block if the source is an OVERRIDE, which should only happen from
      // the main thread before the server has started.
      folly::observer_detail::ObserverManager::waitForAllUpdates();
    }
  }
  void set(T value, AttributeSource source) {
    set(folly::observer::makeStaticObserver<T>(std::move(value)), source);
  }

  void unset(AttributeSource source) {
    rawValues_.choose(source).setValue(folly::none);
    if (source == AttributeSource::OVERRIDE) {
      // See explanation in `.set()`
      folly::observer_detail::ObserverManager::waitForAllUpdates();
    }
  }

 protected:
  ServerAttributeRawValues<folly::observer::SimpleObservable<
      folly::Optional<folly::observer::Observer<T>>>>
      rawValues_{folly::none, folly::none};
  folly::observer::Observer<T> default_;
  mutable folly::DelayedInit<folly::observer::Observer<T>> mergedObserver_;
};

} // namespace detail

template <typename T>
struct ServerAttributeAtomic
    : private apache::thrift::detail::ServerAttributeObservable<T> {
  using apache::thrift::detail::ServerAttributeObservable<
      T>::ServerAttributeObservable;
  using apache::thrift::detail::ServerAttributeObservable<T>::set;
  using apache::thrift::detail::ServerAttributeObservable<T>::unset;
  using apache::thrift::detail::ServerAttributeObservable<T>::getObserver;

  T get() const {
    return *getAtomicObserver();
  }

  const folly::observer::AtomicObserver<T>& getAtomicObserver() const {
    return atomicObserver_.try_emplace(getObserver());
  }

 private:
  mutable folly::DelayedInit<folly::observer::AtomicObserver<T>>
      atomicObserver_;
};

template <typename T>
struct ServerAttributeThreadLocal
    : private apache::thrift::detail::ServerAttributeObservable<T> {
  using apache::thrift::detail::ServerAttributeObservable<
      T>::ServerAttributeObservable;
  using apache::thrift::detail::ServerAttributeObservable<T>::set;
  using apache::thrift::detail::ServerAttributeObservable<T>::unset;
  using apache::thrift::detail::ServerAttributeObservable<T>::getObserver;

  const T& get() const {
    return **getTLObserver();
  }

  const folly::observer::TLObserver<T>& getTLObserver() const {
    return tlObserver_.try_emplace(getObserver());
  }

 private:
  mutable folly::DelayedInit<folly::observer::TLObserver<T>> tlObserver_;
};

} // namespace thrift
} // namespace apache
