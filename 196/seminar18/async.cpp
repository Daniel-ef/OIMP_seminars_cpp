#include <future>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

int SumVectors(const std::vector<int> &v1, const std::vector<int> &v2) {
  std::future<int> fut = std::async([&v1]() {
    return std::accumulate(v1.begin(), v1.end(), 0);
  });
  int sum2 = std::accumulate(v2.begin(), v2.end(), 0);
  return  fut.get() + sum2;
}

int main() {
  std::vector<int> v1{1, 1, 1, 1};
  std::vector<int> v2{4, 4, 4, 4};
  std::cout << SumVectors(v1, v2) << std::endl;
}