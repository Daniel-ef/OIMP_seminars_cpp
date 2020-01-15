#include <iostream>

int main() {
  {
    int a;
  }
//  a = 1;

  double d = 0;
  int b = 1;

  double* d_ptr = &d;
  int* b_ptr = &b;

  std::cout << d_ptr << " " << b_ptr << std::endl;
  std::cout << *d_ptr << " " << *b_ptr << std::endl;

  const char* hello_world = "Hello world!";
  const char* ello_world = hello_world + 1;

  std::cout << hello_world << std::endl;
  std::cout << ello_world << std::endl;

  const int* raw_int_ptr;
  std::cout << raw_int_ptr << std::endl;

  return 0;
}