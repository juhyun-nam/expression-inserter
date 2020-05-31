#include <algorithm>
#include <vector>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "expression_inserter/expression_inserter.h"

TEST_CASE("Insert Valuse") {
  std::vector<int> vector;

  Insert(vector).Values(1);
  CHECK_EQ(vector.size(), 1);

  Insert(vector).Values({1, 1, 1, 1});
  CHECK_EQ(vector.size(), 5);

  Insert(vector).Values(1).Times(5);
  CHECK_EQ(vector.size(), 10);

  vector.clear();
  Insert(vector).Values({1, 2, 3, 4, 5}).Times(10);
  CHECK_EQ(vector.size(), 50);
  int sum = 0;
  std::for_each(vector.begin(), vector.end(), [&sum](int v) { sum += v; });
  CHECK_EQ(sum, 150);
}

TEST_CASE("Insert Select Until") {
  std::vector<int> vector;

  Insert(vector).Select(LEVEL).Until(1);
  CHECK_EQ(vector.size(), 1);

  Insert(vector).Select(LEVEL + 1).Until(4);
  CHECK_EQ(vector.size(), 5);

  Insert(vector).Select(LEVEL + 5).Until(5);
  CHECK_EQ(vector.size(), 10);

  vector.clear();

  /// 모두 0을 넣는 케이스
  Insert(vector).Select(LEVEL % 2).Until(100).Where(LEVEL % 2 != 1);
  CHECK_EQ(vector.size(), 50);
  int sum = 0;
  std::for_each(vector.begin(), vector.end(), [&sum](int v) { sum += v; });
  CHECK_EQ(sum, 0);
}

TEST_CASE("Insert Select From") {
  std::vector<int> vector;
  std::vector<int> source;
  for (int i = 1; i <= 100; ++i) {
    source.push_back(2 * i);
  }

  Insert(vector).Select(ELEMENT).From(source);
  CHECK_EQ(vector.size(), source.size());

  vector.clear();
  Insert(vector).Select(ELEMENT).From(source).Where(ELEMENT % 4 == 0);
  CHECK_EQ(vector.size(), source.size() / 2);
}

TEST_CASE("Insert Select RAND") {
  std::vector<int> vector;

  Insert(vector).Select(RAND(1, 10)).Until(10);
  CHECK_EQ(vector.size(), 10);
}