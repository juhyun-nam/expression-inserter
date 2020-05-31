/// \file arithmetic_expression.h
/// \brief arithmetic expression struct & operation
/// \author juhyun-nam
///

#ifndef EXPRESSION_INSERTER_ARITHMETIC_EXPRESSION_H_
#define EXPRESSION_INSERTER_ARITHMETIC_EXPRESSION_H_

#include <cassert>
#include <functional>
#include "expression_inserter/value_type.h"

namespace detail {

//// 여러 예측하기 힘든 표현식이 많고, upper bound 조건을 확인 하기 힘들어서
/// (-)표현식은 지원하지 않는다 cf. Where (-LEVEL < 1000)
/*
inline Value operator-(Value e) {
  return Value([e](int v) { return -e(v); });
}
*/
inline Value operator+(Value e, int a) {
  return Value([e, a](int v) { return e(v) + a; });
}
inline Value operator+(int a, Value e) {
  return Value([a, e](int v) { return a + e(v); });
}
inline Value operator-(Value e, int a) {
  return Value([e, a](int v) { return e(v) - a; });
}
inline Value operator-(int a, Value e) {
  return Value([a, e](int v) { return a - e(v); });
}
inline Value operator*(Value e, int a) {
  return Value([e, a](int v) { return e(v) * a; });
}
inline Value operator*(int a, Value e) {
  return Value([a, e](int v) { return a * e(v); });
}
inline Value operator%(Value e, int a) {
  return Value([e, a](int v) {
    assert(a);
    return e(v) % a;
  });
}
inline Value operator%(int a, Value e) {
  return Value([a, e](int v) {
    int ev = e(v);
    assert(ev);
    return a % ev;
  });
}
inline Value operator/(int a, Value e) {
  return Value([a, e](int v) {
    int ev = e(v);
    assert(ev);
    return a / ev;
  });
}
inline Value operator/(Value e, int a) {
  return Value([e, a](int v) {
    assert(a);
    return e(v) / a;
  });
}

}  // namespace detail

#endif  // EXPRESSION_INSERTER_ARITHMETIC_EXPRESSION_H_
