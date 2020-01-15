// for i in range(10):
#include <iostream>

int main() {

  for (int i = 0; i < 10; ++i) {
    std::cout << i << " ";
  }

  std::cout << '\n';
  int i = 0;
  std::cout << ++i << '\n';
  std::cout << i++ << '\n';
  ++i;

  int a = 0;
  while (a < 10) {
    std::cout << a << ' ';
    ++a;

    if (a == 5) {
      break;
    }
  }
  std::cout << '\n';

  a = 0;
  do {
    if (a == 5) {
      ++a;
      continue;
    }
    std::cout << a << ' ';
    ++a;
  } while (a < 10);

}