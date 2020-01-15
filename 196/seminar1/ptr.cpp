#include <iostream>
#include <string>

int main() {
  int a = 1;
  int* a_ptr = &a;
  std::cout << a_ptr << '\n';
  std::cout << *a_ptr << '\n';
}
