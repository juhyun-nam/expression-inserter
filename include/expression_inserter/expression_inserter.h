/// \file expression_inserter.h
/// \brief expression_inserter main header file
/// \author juhyun-nam
///

#ifndef EXPRESSION_INSERTER_EXPRESSION_INSERTER_H_
#define EXPRESSION_INSERTER_EXPRESSION_INSERTER_H_

namespace detail {

template <typename T>
class Insertion {};
}  // namespace detail

template <typename Container>
auto Insert(Container&) -> detail::Insertion<Container> {
  return detail::Insertion<Container>();
}
#endif  // EXPRESSION_INSERTER_EXPRESSION_INSERTER_H_
