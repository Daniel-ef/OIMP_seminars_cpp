#include <iostream>

using namespace std;

int max(int a, int b) {
  std::cout << "my_max" << "\n";
  return a;
};

int main() {
  int a = 2;

  max(1, 2);

  switch (a) {
    case 1:
      std::cout << "1\n";
      break;
    case 2:
      std::cout << "2\n";
      break;
    default:
      std::cout << "3\n";
  }

}
