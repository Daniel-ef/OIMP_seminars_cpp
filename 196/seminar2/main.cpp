#include <iostream>

int main() {

  double d = 8.9;
  int a = 1;

  int* a_ptr = &a;
  double* d_ptr = &d;

  std::cout << a_ptr << " " << d_ptr << std::endl;

  std::cout << *((double*)(++a_ptr)) << std::endl;

  int* raw_ptr;
  std::cout << raw_ptr << std::endl;
  std::cout << *raw_ptr;




}
