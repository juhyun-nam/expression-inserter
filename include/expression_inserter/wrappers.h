/// \file expression_inserter.h
/// \brief expression_inserter main header file
/// \author juhyun-nam
///

#ifndef EXPRESSION_INSERTER_WRAPPERS_H_
#define EXPRESSION_INSERTER_WRAPPERS_H_

#include <initializer_list>

#include "expression_inserter/arithmetic_expression.h"
#include "expression_inserter/comparison_expression.h"
#include "expression_inserter/condition_type.h"
#include "expression_inserter/logical_expression.h"
#include "expression_inserter/main_operator.h"
#include "expression_inserter/value_type.h"

namespace detail {

template <typename Container, typename Source>
class FromWrapper final {
 public:
  FromWrapper(Container* container, const Value& arith, const Source& source)
      : container_(container), arith_(arith), source_(source) {}

  auto Where(const Cond& where) {
    MakeData(container_, arith_, source_, where);
    container_ = nullptr;
  }

  ~FromWrapper() {
    if (container_) {
      MakeData(container_, arith_, source_);
      container_ = nullptr;
    }
  }

 private:
  Container* container_{};
  Value arith_{};
  const Source& source_;
};
template <typename Container>
class WhileWrapper final {
 public:
  WhileWrapper(Container* container, const Value& arith, const Cond& while_cond)
      : container_(container), arith_(arith), while_cond_(while_cond) {}

  auto Where(const Cond& where) {
    MakeData(container_, arith_, while_cond_, where);
    container_ = nullptr;
  }

  ~WhileWrapper() {
    if (container_) {
      MakeData(container_, arith_, while_cond_);
      container_ = nullptr;
    }
  }

 private:
  Container* container_{};
  Value arith_{};
  Cond while_cond_{};
};
template <typename Container>
class UntilWrapper final {
 public:
  UntilWrapper(Container* container, const Value& arith, int upper)
      : container_(container), arith_(arith), upper_(upper) {}

  auto Where(const Cond& where) {
    MakeData(container_, arith_, upper_, where);
    container_ = nullptr;
  }

  ~UntilWrapper() {
    if (container_) {
      MakeData(container_, arith_, upper_);
      container_ = nullptr;
    }
  }

 private:
  Container* container_{};
  Value arith_{};
  int upper_{};
};

template <typename Container>
class SelectWrapper final {
 public:
  SelectWrapper(Container* container, const Value& arith)
      : container_(container), arith_(arith) {}

  template <typename Source>
  auto From(const Source& source) {
    return FromWrapper<Container, Source>(container_, arith_, source);
  }
  auto While(const Cond& while_cond) {
    return WhileWrapper<Container>(container_, arith_, while_cond);
  }
  auto Until(int upper) {
    return UntilWrapper<Container>(container_, arith_, upper);
  }

 private:
  Container* container_{};
  Value arith_{};
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
  auto Values(std::initializer_list<int> list) {
    return ValuesWrapper<Container>(container_, list);
  }
  /// evaluation없이 값을 넣을 경우
  auto Values(int a) { return ValuesWrapper<Container>(container_, a); }

  /// LEVEL과 같은 대상을 insert 할 때
  auto Select(Value arith) {
    return SelectWrapper<Container>(container_, arith);
  }

 private:
  Container* container_{};
};

}  // namespace detail

#endif  // EXPRESSION_INSERTER_WRAPPERS_H_
