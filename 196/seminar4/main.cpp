#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{1, 2, 3};

  std::cout << v[50] << std::endl;
  std::cout << v.at(50) << std::endl;

}
