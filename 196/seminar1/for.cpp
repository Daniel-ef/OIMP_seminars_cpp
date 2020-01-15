#include <iostream>

int main() {

  // for i in range(0, 10):
  for (int i = 0; i < 10; i++) {
    int a = 1;
    std::cout << i << " ";
  }

  a += 1;


  std::cout << '\n';

  int i = 0;

  std::cout << ++i << " ";
  std::cout << i++ << " ";
  std::cout << i << '\n';

  while (i < 10) {
    std::cout << i << " ";
    ++i;
    if (i == 5) {
      break;
    }
  }
  std::cout << i << '\n';

  do {
    if (i == 5) {
      ++i
      continue;
    }
    std::cout << i << " ";
    ++i;
  } while (i < 10);
}
