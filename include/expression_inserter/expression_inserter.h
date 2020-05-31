/// \file expression_inserter.h
/// \brief expression_inserter main header file
/// \author juhyun-nam
///

#ifndef EXPRESSION_INSERTER_EXPRESSION_INSERTER_H_
#define EXPRESSION_INSERTER_EXPRESSION_INSERTER_H_

#include "expression_inserter/keyword_type.h"
#include "expression_inserter/wrappers.h"

static constexpr detail::Level LEVEL{};
static constexpr detail::Level ELEMENT{};
using RAND = detail::Rand;

template <typename Container>
auto Insert(Container& container) -> detail::InsertWrapper<Container> {
  return detail::InsertWrapper<Container>(&container);
}

#endif  // EXPRESSION_INSERTER_EXPRESSION_INSERTER_H_
