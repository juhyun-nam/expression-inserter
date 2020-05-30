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