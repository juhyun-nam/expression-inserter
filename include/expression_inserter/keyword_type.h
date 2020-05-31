/// \file keyword_type.h
/// \brief expression에서 사용하는 여러 keyword
/// \author juhyun-nam
///

#ifndef EXPRESSION_INSERTER_KEYWORD_TYPE_H_
#define EXPRESSION_INSERTER_KEYWORD_TYPE_H_

#include <cstdlib>
#include <ctime>

#include "expression_inserter/value_type.h"

namespace detail {

/// 기본적인 LEVEL의 type이 되는 구조체. a -> a인 기본적인 Values로 변환 가능
struct Level {
  operator Value() const { return Value{}; }
};

/// RAND의 구조체
struct Rand {
  Rand(int min, int max) : min_(min), max_(max) {}
  operator Value() const {
    std::srand(time(nullptr));
    auto min = min_;
    auto max = max_;
    return Value{[min, max](int v) { return (std::rand() % max) + min; }};
  }

 private:
  int min_{};
  int max_{};
};

}  // namespace detail

#endif  // EXPRESSION_INSERTER_KEYWORD_TYPE_H_
