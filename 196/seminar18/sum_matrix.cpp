#include <iostream>
#include <future>
#include <vector>
#include <random>
#include "profile.h"

using Matrix = std::vector<std::vector<int>>;


void GenerateMatrixSingleThread(Matrix& matrix, size_t from, size_t to) {
  for (; from != to; ++from) {
    auto& row = matrix[from];
    for (auto& element: row) {
      element = std::rand();
    }
  }
}

void RunGenerationAsync(Matrix& matrix, size_t threads_num) {
  size_t page_size = std::ceil(matrix.size() / threads_num);
  size_t pages = std::ceil(matrix.size() / page_size);

  std::vector<std::future<void>> futures;

  for (size_t i = 0; i < pages; ++i) {
    size_t from = i * page_size;
    size_t to = std::min((i + 1) * page_size, matrix.size());
    futures.push_back(std::async(GenerateMatrixSingleThread,
        std::ref(matrix), from, to));
  }

  for (auto&& future : futures) {
    future.get();
  }
}

int SumMatrix(const Matrix& matrix) {
  int sum = 0;
  for (const auto& row : matrix) {
    for (const auto &element: row) {
      sum += element;
    }
  }
  return sum;
}

int main() {
  size_t N = 2000; // rows
  size_t M = 5000; // cols

  Matrix matrix(N, std::vector<int>(M));
  int sum;
  {
    LOG_DURATION("Generate matrix in single thread");
    GenerateMatrixSingleThread(matrix, 0, N);
  }
  {
    LOG_DURATION("Generate matrix in multiple threads");
    RunGenerationAsync(matrix, 100);
  }
  {
    LOG_DURATION("Sum matrix");
    sum = SumMatrix(matrix);
  }

  std::cout << sum << std::endl;

}
