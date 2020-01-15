#include <iostream>

/*
 * python
 * import my_std
 * my_std.max(1, 2)
 *
 */
// 


namespace std {
  int max(int a, int b);
}

namespace my_std {
  int my_max(int a, int b);
}

// main() -> int:
int main() {

    int a = 1;

    long l = 1;

  /*
  int32_t
  int64_t
  uint8_t
  */
  std::cout << sizeof(l) << std::endl;

  char ch = 'a';
  std::cout << int(ch) << std::endl;
  std::cout << static_cast<int>(ch) << std::endl;

  int i = (1 << 16) + 1;
  char i_to_char = i;
  std::cout << i_to_char << " " << int(i_to_char) << std::endl;


  int a1, a2, a3;
  std::cout << "input: ";
  std::cin >> a1 >> a2 >> a3;
  std::cout << a1  << a2 << a3 << '\n';

  return 0;
}

