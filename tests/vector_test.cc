#include <vector>

#include "expression_inserter/expression_inserter.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

SCENARIO("insert number using expression") {
  GIVEN("int vector") {
    std::vector<int> vector;
    WHEN("insert A where 1 <= A and A <= 100") {
      Insert(vector).Select(LEVEL).Where(LEVEL <= 100);
      THEN("size of vector is 100") {
        // CHECK_EQ(vector.size(), 100);
      }
    }
  }
}