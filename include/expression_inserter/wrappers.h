/// \file expression_inserter.h
/// \brief expression_inserter main header file
/// \author juhyun-nam
///

#ifndef EXPRESSION_INSERTER_WRAPPERS_H_
#define EXPRESSION_INSERTER_WRAPPERS_H_

#include <initializer_list>

#include "expression_inserter/arithmetic_expression.h"
#include "expression_inserter/logical_expression.h"
#include "expression_inserter/main_operator.h"

namespace detail {

template <typename Container>
class WhereWrapper final {
 public:
  WhereWrapper(Container* container, const Arith& arith, const Comp& comp)
      : container_(container), arith_(arith), comp_(comp) {}

  void Shuffle() {
    MakeDataShuffled(container_, arith_, comp_);
    container_ = nullptr;
  }
  ~WhereWrapper() {
    MakeData(container_, arith_, comp_);
    container_ = nullptr;
  }

 private:
  Container* container_{};
  Arith arith_{};
  Comp comp_{};
};

/// Where 함수 wrapper
template <typename Container>
class SelectWrapper final {
 public:
  SelectWrapper(Container* container, const Arith& arith)
      : container_(container), arith_(arith) {}

  WhereWrapper<Container> Where(const detail::Comp& comp) {
    return WhereWrapper<Container>(container_, arith_, comp);
  }

 private:
  Container* container_{};
  Arith arith_{};
};

template <typename Container>
class ValuesWrapper final {
 public:
  ValuesWrapper(Container* container, std::vector<int> list)
      : container_(container), list_(list) {}
  ValuesWrapper(Container* container, int single)
      : container_(container), list_({single}) {}

  /// values의 값을 반복해서 insert
  void Times(int count) { loop_count_ = count; }

  ~ValuesWrapper() {
    for (int i = 0; i < loop_count_; ++i)
      MakeData(container_, list_);
  }

 private:
  Container* container_{};
  std::vector<int> list_{};
  int loop_count_ = 1;
};

/// Select 함수wrapper
template <typename Container>
class InsertWrapper final {
 public:
  explicit InsertWrapper(Container* c) : container_(c) {}

  /// 여러 값을 evaluation없이 넣을 경우
  ValuesWrapper<Container> Values(std::initializer_list<int> list) {
    return ValuesWrapper<Container>(container_, list);
  }
  /// evaluation없이 값을 넣을 경우
  ValuesWrapper<Container> Values(int a) {
    return ValuesWrapper<Container>(container_, a);
  }

  /// LEVEL과 같은 대상을 insert 할 때
  SelectWrapper<Container> Select(detail::Arith arith) {
    return SelectWrapper<Container>(container_, arith);
  }

 private:
  Container* container_{};
};

}  // namespace detail

#endif  // EXPRESSION_INSERTER_WRAPPERS_H_
