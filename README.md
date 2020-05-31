# expression-inserter

[![Project Status: Active – The project has reached a stable, usable state and is being actively developed.](https://www.repostatus.org/badges/latest/active.svg)](https://www.repostatus.org/#active)
[![Build Status](https://travis-ci.org/juhyun-nam/expression-inserter.svg?branch=master)](https://travis-ci.org/juhyun-nam/expression-inserter)
[![Total alerts](https://img.shields.io/lgtm/alerts/g/juhyun-nam/expression-inserter.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/juhyun-nam/expression-inserter/alerts/)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/juhyun-nam/expression-inserter.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/juhyun-nam/expression-inserter/context:cpp)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/9233910b31a94542bf7552a0332647a2)](https://app.codacy.com/manual/juhyun-nam/expression-inserter?utm_source=github.com&utm_medium=referral&utm_content=juhyun-nam/expression-inserter&utm_campaign=Badge_Grade_Dashboard)
[![codecov](https://codecov.io/gh/juhyun-nam/expression-inserter/branch/master/graph/badge.svg)](https://codecov.io/gh/juhyun-nam/expression-inserter)

## 목적

여러 expression을 사용해서 container에 값을 넣는 helper function.

## The Gist

```cpp
  std::vector<int> vector;

  Insert(vector).Values({1, 1, 1, 1});
  Insert(vector).Values(1).Times(5);
  Insert(vector).Values({1, 2, 3, 4, 5}).Times(10);

  Insert(vector).Select(LEVEL + 5).Until(5);
  Insert(vector).Select(LEVEL % 2).Until(100).Where(LEVEL % 2 != 1);

  std::vector<int> source(100);
  Insert(vector).Select(ELEMENT).From(source).Where(ELEMENT % 4 == 0);
```
