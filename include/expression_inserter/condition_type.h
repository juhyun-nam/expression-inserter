/// \file condition_type.h
/// \brief condition expression을 담는 구조체 정의
/// \author juhyun-nam
///

#ifndef EXPRESSION_INSERTER_CONDITION_TYPE_H_
#define EXPRESSION_INSERTER_CONDITION_TYPE_H_

#include <functional>

namespace detail {

/// LEVEL과 int, Arith와 int의 comparison, logical 연산 동작을 담는 구조체
class Cond {
 public:
  Cond() = default;
  explicit Cond(std::function<bool(int)> fn) : expr_(fn) {}
  bool operator()(int v) const { return expr_(v); }

 private:
  std::function<bool(int)> expr_{};
};

}  // namespace detail
#endif  // EXPRESSION_INSERTER_CONDITION_TYPE_H_
