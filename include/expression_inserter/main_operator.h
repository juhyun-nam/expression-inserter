/// \file main_operator.h
/// \brief make data functional defined header file
/// \author juhyun-nam
///

#ifndef EXPRESSION_INSERTER_MAIN_OPERATOR_H_
#define EXPRESSION_INSERTER_MAIN_OPERATOR_H_

#include <vector>

#include "expression_inserter/condition_type.h"
#include "expression_inserter/value_type.h"

namespace detail {

/* FUNCTIONAL ****************************************************************/

/// raw int list를 직접 container에 담는 경우
/// values에 해당
template <typename Container>
inline void MakeData(Container* container, const std::vector<int>& list) {
  for (auto it : list)
    container->push_back(it);
}

/// from
template <typename Container, typename Source>
inline void MakeData(Container* cont,
                     const Value& arith,
                     const Source& source) {
  /// start from 1
  for (auto it : source) {
    auto value = arith(it);
    cont->push_back(value);
  }
}
/// from
template <typename Container, typename Source>
inline void MakeData(Container* cont,
                     const Value& arith,
                     const Source& source,
                     const Cond& where) {
  /// start from 1
  for (auto it : source) {
    if (!where(it))
      continue;
    auto value = arith(it);
    cont->push_back(value);
  }
}
/// while
template <typename Container>
inline void MakeData(Container* cont,
                     const Value& arith,
                     const Cond& while_cond) {
  /// start from 1
  int index = 0;
  int maximum_loop_count = 100000;
  while (while_cond(++index)) {
    /// 사용자가 limit 조건을 주지 않았을 때, assert를 발생시킨다.
    assert(index < maximum_loop_count);
    auto value = arith(index);
    cont->push_back(value);
  }
}
/// while & where
template <typename Container>
inline void MakeData(Container* cont,
                     const Value& arith,
                     const Cond& while_cond,
                     const Cond& where) {
  /// start from 1
  int index = 0;
  int maximum_loop_count = 100000;
  while (while_cond(++index)) {
    /// 사용자가 limit 조건을 주지 않았을 때, assert를 발생시킨다.
    assert(index < maximum_loop_count);
    if (!where(index))
      continue;
    auto value = arith(index);
    cont->push_back(value);
  }
}
/// until
template <typename Container>
inline void MakeData(Container* cont, const Value& arith, int upper) {
  /// start from 1
  int index = 0;
  int maximum_loop_count = 100000;
  while (++index <= upper) {
    /// 사용자가 limit 조건을 주지 않았을 때, assert를 발생시킨다.
    assert(index < maximum_loop_count);
    auto value = arith(index);
    cont->push_back(value);
  }
}
/// until & where
template <typename Container>
inline void MakeData(Container* cont,
                     const Value& arith,
                     int upper,
                     const Cond& where) {
  /// start from 1
  int index = 0;
  int maximum_loop_count = 100000;
  while (++index <= upper) {
    /// 사용자가 limit 조건을 주지 않았을 때, assert를 발생시킨다.
    assert(index < maximum_loop_count);
    if (!where(index))
      continue;
    auto value = arith(index);
    cont->push_back(value);
  }
}

}  // namespace detail

#endif  // EXPRESSION_INSERTER_MAIN_OPERATOR_H_
