/// \file logical_expression.h
/// \brief logical expression struct & operation
/// \author juhyun-nam
///

#ifndef EXPRESSION_INSERTER_LOGICAL_EXPRESSION_H_
#define EXPRESSION_INSERTER_LOGICAL_EXPRESSION_H_

#include "expression_inserter/condition_type.h"

namespace detail {

// logical
inline Cond operator!(Cond c) {
  return Cond([c](int v) { return !c(v); });
}
inline Cond operator&&(Cond l, Cond r) {
  return Cond([l, r](int v) { return l(v) && r(v); });
}
inline Cond operator||(Cond l, Cond r) {
  return Cond([l, r](int v) { return l(v) || r(v); });
}

}  // namespace detail
#endif  // EXPRESSION_INSERTER_LOGICAL_EXPRESSION_H_
