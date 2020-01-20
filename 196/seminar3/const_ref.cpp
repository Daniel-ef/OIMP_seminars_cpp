#include <iostream>
#include <vector>

void print_vector(const std::vector<int> v) {
  for (const int el : v) {
    std::cout << el << " ";
  }
}

int sum_vector(const std::vector<int>& v) {
  int sum = 0;
  for (const int el : v) {
    sum += el;
  }
  return sum;
}

int main() {
  const int a = 2;
//  a = 3;

  int b = 2;
  int& b_ref = b;
  b_ref = 3;
  std::cout << b << std::endl;

  std::vector<int> v(100000000);
//  std::cout << sum_vector(v) << '\n';

  int c = 3;
  int* c_ptr = &c; // get address
  int& c_ref = c;

  std::cout << c_ptr << " " << c_ref << std::endl;
}
