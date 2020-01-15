#include <iostream>

char a = 'a';
char b = 'b';

int main() {

  if (a < b) {
    std::cout << "a < b" << std::endl;
  } else if (a > b) {
    a = 'c';
  } else if (a == b) {

  } else {
  }

  char a = 'a';

  switch (a) {
    case 'a':
      std::cout << 'a' << '\n';
      break;
    case 'b':
      std::cout << 'b' << '\n';
      break;
    default:
      std::cout << 'c' << '\n';
  }

}
