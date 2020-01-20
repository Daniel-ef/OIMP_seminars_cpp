#include <iostream>
#include <random>
#include <ctime>

int main() {
  size_t n = 10;
  std::vector<int> v(n);

//  std::srand(time(0));

  for(int& el : v) {
    el = std::rand() % 20; // std::rand [0, RAND_MAX]
    std::cout << el << " ";
  }
}
