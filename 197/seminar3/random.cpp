#include <iostream>
#include <random>
#include <ctime>

class Student {

  int getAge() const {
    return age;
  }

  std::string name;
  int age;
};

int main() {
  std::srand(std::time(0));

  std::vector<int> v(10);
  for (int& el : v) {
    el = std::rand() % 20; // std::rand [0, RAND_MAX]
  }

  for (int el : v) {
    std::cout << el << " ";
  }

  std::cin.getline
}

