#include <iostream>
#include <vector>
#include <deque>
#include "profile.h"

int main() {
  size_t N = 50000000;
  std::vector<int> v;
  {
    LOG_DURATION("vector");
    for (size_t i = 0; i < N; ++i) {
      v.push_back(i);
    }
  }
  std::deque<int> d;
  {
    LOG_DURATION("deque");
    for (size_t i = 0; i < N; ++i) {
      d.push_back(i);
    }
  }

  {
    LOG_DURATION("sum_vector");
    size_t sum = 0;
    for (const auto& el : v) {
      sum += el;
    }
    std::cout << sum << '\n';
  }

  {
    LOG_DURATION("sum_deque");
    size_t sum = 0;
    for (const auto& el : d) {
      sum += el;
    }
    std::cout << sum << '\n';
  }

}
