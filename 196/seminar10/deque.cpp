#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include "profile.h"

std::pair<int, int> ret_pair() {
  std::pair<int, int> p{1, 2};
  // ...
  return p;
}

int main() {
  std::vector<std::array<int, 5>> va(5, std::array<int, 5>{});
  va.emplace_back(std::array<int, 5>());


  size_t N;
  std::cin >> N;
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
