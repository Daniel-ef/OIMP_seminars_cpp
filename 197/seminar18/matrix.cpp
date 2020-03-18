#include <future>
#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
#include "profile.h"

using Matrix = std::vector<std::vector<int>>;

void GenerateSingleThread(Matrix& matrix, size_t from, size_t to) {
  for (; from != to; ++from) {
    auto& row = matrix[from];
    for (auto& element : row) {
      element = std::rand();
    }
  }
}

void GenerateMultiThread(Matrix& matrix, size_t threads) {
  size_t page_size = std::ceil(matrix.size() / threads);
  size_t pages = std::ceil(matrix.size() / page_size);

  std::vector<std::future<void>> futures;

  for (size_t i = 0; i < pages; ++i) {
    futures.push_back(std::async(
        GenerateSingleThread,
        std::ref(matrix),
        i * page_size,
        std::min((i + 1) * page_size, matrix.size())
        ));
  }
  for (auto&& fut : futures) {
    fut.get();
  }

}

int SumSingleThread(const Matrix& matrix) {
  int sum = 0;
  for (const auto& row : matrix) {
    sum += std::accumulate(row.begin(), row.end(), sum);
  }
  return sum;
}

int main() {
  size_t N = 10000;
  size_t M = 5000;
  Matrix m(N, std::vector<int>(M));

  {
    LOG_DURATION("Generate single")
    GenerateSingleThread(m, 0, N);
  }

  {
    LOG_DURATION("Generate multi");
    GenerateMultiThread(m, 8);
  }

  {
    LOG_DURATION("Sum")
    std::cout << SumSingleThread(m) << std::endl;
  }

}
