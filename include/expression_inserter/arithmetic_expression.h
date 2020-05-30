/// \file arithmetic_expression.h
/// \brief arithmetic expression struct & operation
/// \author juhyun-nam
///

#ifndef EXPRESSION_INSERTER_ARITHMETIC_EXPRESSION_H_
#define EXPRESSION_INSERTER_ARITHMETIC_EXPRESSION_H_

#include <cassert>
#include <functional>

namespace detail {

/// LEVEL과 int의 arithmetic operation 동작을 담는 구조체
struct Arith {
  Arith() {
    expr = [](int v) { return v; };
  }
  explicit Arith(std::function<int(int)> fn) : expr(fn) {}
  std::function<int(int)> expr;
};

// arithmetic
inline Arith operator-(Arith e) {
  return Arith([e](int v) { return -e.expr(v); });
}
inline Arith operator+(Arith e, int a) {
  return Arith([e, a](int v) { return e.expr(v) + a; });
}
inline Arith operator+(int a, Arith e) {
  return Arith([a, e](int v) { return a + e.expr(v); });
}
inline Arith operator-(Arith e, int a) {
  return Arith([e, a](int v) { return e.expr(v) - a; });
}
inline Arith operator-(int a, Arith e) {
  return Arith([a, e](int v) { return a - e.expr(v); });
}
inline Arith operator*(Arith e, int a) {
  return Arith([e, a](int v) { return e.expr(v) * a; });
}
inline Arith operator*(int a, Arith e) {
  return Arith([a, e](int v) { return a * e.expr(v); });
}
inline Arith operator%(Arith e, int a) {
  return Arith([e, a](int v) {
    assert(!a);
    return e.expr(v) % a;
  });
}
inline Arith operator%(int a, Arith e) {
  return Arith([a, e](int v) {
    int ev = e.expr(v);
    assert(!ev);
    return a % ev;
  });
}
inline Arith operator/(int a, Arith e) {
  return Arith([a, e](int v) {
    int ev = e.expr(v);
    assert(!ev);
    return a / ev;
  });
}
inline Arith operator/(Arith e, int a) {
  return Arith([e, a](int v) {
    assert(!a);
    return e.expr(v) / a;
  });
}

}  // namespace detail

#endif  // EXPRESSION_INSERTER_ARITHMETIC_EXPRESSION_H_
