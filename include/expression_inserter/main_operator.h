/// \file main_operator.h
/// \brief make data functional defined header file
/// \author juhyun-nam
///

#ifndef EXPRESSION_INSERTER_MAIN_OPERATOR_H_
#define EXPRESSION_INSERTER_MAIN_OPERATOR_H_

#include <functional>
#include <vector>

#include "expression_inserter/arithmetic_expression.h"
#include "expression_inserter/logical_expression.h"

namespace detail {

/* FUNCTIONAL ****************************************************************/

/// raw int list를 직접 container에 담는 경우
template <typename Container>
inline void MakeData(Container* container, const std::vector<int>& list) {
  for (auto it : list)
    container->push_back(it);
}

/// container에 data를 담는 main operator
template <typename Container>
inline void MakeData(Container* container,
                     const Arith& arith_list,
                     const Comp& comp_list) {}

template <typename Container>
inline void MakeDataShuffled(Container* container,
                             const Arith& arith_list,
                             const Comp& comp_list) {}

}  // namespace detail

#endif  // EXPRESSION_INSERTER_MAIN_OPERATOR_H_
