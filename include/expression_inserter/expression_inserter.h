/// \file expression_inserter.h
/// \brief expression_inserter main header file
/// \author juhyun-nam
///

#ifndef EXPRESSION_INSERTER_EXPRESSION_INSERTER_H_
#define EXPRESSION_INSERTER_EXPRESSION_INSERTER_H_

namespace detail {

struct Expr {};
struct Level {
  operator Expr() const { return Expr{}; }
};

// comparison

static inline Expr operator<=(Level, int) {
  return Expr{};
}

// arithmetic

// logical

template <typename Container>
class Insertion {};
template <typename Container>
class WhereWrapper {
 public:
  auto Where(const detail::Expr) -> Insertion<Container> {
    return Insertion<Container>();
  }
};
template <typename Container>
class SelectWrapper {
 public:
  auto Select(detail::Expr) -> WhereWrapper<Container> {
    return WhereWrapper<Container>();
  }
};
}  // namespace detail

static constexpr detail::Level LEVEL{};
template <typename Container>
auto Insert(Container&) -> detail::SelectWrapper<Container> {
  return detail::SelectWrapper<Container>();
}
#endif  // EXPRESSION_INSERTER_EXPRESSION_INSERTER_H_
