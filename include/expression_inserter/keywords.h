/// \file keywords.h
/// \brief expression에서 사용하는 여러 keyword
/// \author juhyun-nam
///

#ifndef EXPRESSION_INSERTER_KEYWORDS_H_
#define EXPRESSION_INSERTER_KEYWORDS_H_

#include "expression_inserter/arithmetic_expression.h"

namespace detail {

/// 기본적인 LEVEL의 type이 되는 구조체. a -> a인 기본적인 Arith로 변환 가능
struct Level {
  operator Arith() const { return Arith{}; }
};

}  // namespace detail

#endif  // EXPRESSION_INSERTER_KEYWORDS_H_
