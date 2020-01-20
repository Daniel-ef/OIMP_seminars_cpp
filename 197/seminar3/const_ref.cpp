#include <iostream>
#include <vector>

int my_sum(const int a, const int b) {
  return a + b;
}

void print_num(int a) {
  std::cout << a << std::endl;
}

void print_vector(std::vector<int> v) {
  for (int el: v) {
    std::cout << el << " ";
  }
  std::cout << '\n';
}

int sum_vector(const std::vector<int>& v) {
  int sum = 0;
  for (int el: v) {
    sum += el;
  }
  return sum;
}

int main() {
  const int a = 10;
  int b = 22;

  std::cout << my_sum(a, b) << '\n';

  std::vector<int> v(40000000, 0);
//  print_vector(v);
//  std::cout << sum_vector(v) << '\n';

  std::find(v.begin(), v.end(), 5);

  int int_a = 5;
  int& ref_a = int_a;
  ref_a = 6;
  std::cout << int_a << '\n';

}
