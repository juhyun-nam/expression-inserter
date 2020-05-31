/// \file value_type.h
/// \brief value expression을 담는 구조체 정의
/// \author juhyun-nam
///

#ifndef EXPRESSION_INSERTER_VALUE_TYPE_H_
#define EXPRESSION_INSERTER_VALUE_TYPE_H_

#include <functional>

namespace detail {

/// LEVEL과 int의 arithmetic operation 동작을 담는 구조체
class Value {
 public:
  Value() {
    expr_ = [](int v) { return v; };
  }
  explicit Value(std::function<int(int)> fn) : expr_(fn) {}
  int operator()(int v) const { return expr_(v); }

 private:
  std::function<int(int)> expr_;
};

}  // namespace detail

#endif  // EXPRESSION_INSERTER_VALUE_TYPE_H_
