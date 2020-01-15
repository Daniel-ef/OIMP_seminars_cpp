#include <iostream>

int main() {
  std::cout << "Hello, World!" << std::endl;

  char a = 'a';

  int i = 1 << 16;

  std::cout << a << " " << i << std::endl;

  int i_a = int(a);
  int i_aa = static_cast<int>(a);

  char char_from_int = static_cast<int>(i);
  std::cout << static_cast<int>('a') << std::endl;
  std::cout << char_from_int << std::endl;

  std::cout << '\n';
  char b = 'b';
  char c = 'c';

  if (b > c) {
    std::cout << 1 << '\n';
  } else if (b < c) {
    std::cout << "b < c" << '\n';
  } else {

  }

  /*
   * a = int(input())
   */

  int input_a;
  std::cout << "in: ";
  std::cin >> input_a;

  std::cout << input_a << '\n';

  int32_t aaa;
  uint32_t aa;


  return 0;
}
