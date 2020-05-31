/// \file comparison_expression.h
/// \brief comparison expression struct & operation
/// \author juhyun-nam
///

#ifndef EXPRESSION_INSERTER_COMPARISON_EXPRESSION_H_
#define EXPRESSION_INSERTER_COMPARISON_EXPRESSION_H_

#include "expression_inserter/condition_type.h"
#include "expression_inserter/value_type.h"

namespace detail {

inline Cond operator==(Value l, int r) {
  return Cond([l, r](int v) { return l(v) == r; });
}
inline Cond operator!=(Value l, int r) {
  return Cond([l, r](int v) { return l(v) != r; });
}
inline Cond operator<(Value l, int r) {
  return Cond([l, r](int v) { return l(v) < r; });
}
inline Cond operator>(Value l, int r) {
  return Cond([l, r](int v) { return l(v) > r; });
}
inline Cond operator<=(Value l, int r) {
  return Cond([l, r](int v) { return l(v) <= r; });
}
inline Cond operator>=(Value l, int r) {
  return Cond([l, r](int v) { return l(v) >= r; });
}

inline Cond operator==(int l, Value r) {
  return Cond([l, r](int v) { return l == r(v); });
}
inline Cond operator!=(int l, Value r) {
  return Cond([l, r](int v) { return l != r(v); });
}
inline Cond operator<(int l, Value r) {
  return Cond([l, r](int v) { return l < r(v); });
}
inline Cond operator>(int l, Value r) {
  return Cond([l, r](int v) { return l > r(v); });
}
inline Cond operator<=(int l, Value r) {
  return Cond([l, r](int v) { return l <= r(v); });
}
inline Cond operator>=(int l, Value r) {
  return Cond([l, r](int v) { return l >= r(v); });
}

inline Cond operator==(Value l, Value r) {
  return Cond([l, r](int v) { return l(v) == r(v); });
}
inline Cond operator!=(Value l, Value r) {
  return Cond([l, r](int v) { return l(v) != r(v); });
}
inline Cond operator<(Value l, Value r) {
  return Cond([l, r](int v) { return l(v) < r(v); });
}
inline Cond operator>(Value l, Value r) {
  return Cond([l, r](int v) { return l(v) > r(v); });
}
inline Cond operator<=(Value l, Value r) {
  return Cond([l, r](int v) { return l(v) <= r(v); });
}
inline Cond operator>=(Value l, Value r) {
  return Cond([l, r](int v) { return l(v) >= r(v); });
}

}  // namespace detail
#endif  // EXPRESSION_INSERTER_COMPARISON_EXPRESSION_H_
