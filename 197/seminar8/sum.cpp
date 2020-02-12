#include <iostream>

int main() {
  size_t a = 0;
  for (size_t i = 0; i < 10; ++i) {
    a += i;
  }
  std::cout << a;
}