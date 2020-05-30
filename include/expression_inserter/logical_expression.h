/// \file logical_expression.h
/// \brief logical expression struct & operation
/// \author juhyun-nam
///

#ifndef EXPRESSION_INSERTER_LOGICAL_EXPRESSION_H_
#define EXPRESSION_INSERTER_LOGICAL_EXPRESSION_H_

#include <functional>

#include "expression_inserter/arithmetic_expression.h"

namespace detail {

/// LEVEL과 int, Arith와 int의 comparison, logical 연산 동작을 담는 구조체
struct Comp {
  Comp() = default;
  explicit Comp(std::function<bool(int)> fn) : expr(fn) {}
  std::function<bool(int)> expr{};
};

// comparison

inline Comp operator==(Arith l, Arith r) {
  return Comp([l, r](int v) { return l.expr(v) == r.expr(v); });
}
inline Comp operator!=(Arith l, Arith r) {
  return Comp([l, r](int v) { return l.expr(v) != r.expr(v); });
}
inline Comp operator<(Arith l, Arith r) {
  return Comp([l, r](int v) { return l.expr(v) < r.expr(v); });
}
inline Comp operator>(Arith l, Arith r) {
  return Comp([l, r](int v) { return l.expr(v) > r.expr(v); });
}
inline Comp operator<=(Arith l, Arith r) {
  return Comp([l, r](int v) { return l.expr(v) <= r.expr(v); });
}
inline Comp operator>=(Arith l, Arith r) {
  return Comp([l, r](int v) { return l.expr(v) >= r.expr(v); });
}

// logical
inline Comp operator!(Comp c) {
  return Comp([c](int v) { return !c.expr(v); });
}
inline Comp operator&&(Comp l, Comp r) {
  return Comp([l, r](int v) { return l.expr(v) && r.expr(v); });
}
inline Comp operator||(Comp l, Comp r) {
  return Comp([l, r](int v) { return l.expr(v) || r.expr(v); });
}
}  // namespace detail
#endif  // EXPRESSION_INSERTER_LOGICAL_EXPRESSION_H_
