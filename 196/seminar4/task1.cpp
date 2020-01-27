#include <random>
#include <ctime>

std::srand(std::time(0)); // randomize seed

int a = std::rand();  // [0, RAND_MAX]



std::vector<std::vector<int>>
multiply_matrix(
    const std::vector<std::vector<int>>& Matrix1,
    const std::vector<std::vector<int>>& Matrix2,
    lambda(std::vector<int>, std::vector<int>) -> int) ; // col * row


template <typename T>
dot_matrix(, , T lambda);
