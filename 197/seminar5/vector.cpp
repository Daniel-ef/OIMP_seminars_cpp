#include <iostream>
#include <vector>


int main() {
  std::vector<int> v{4};
  for (int i = 0; i < 1000; ++i) {
    v.push_back(i);
  }
  auto it = v.end() - 1;
  std::cout << v.capacity() << std::endl;

  for (int i = 0; i < 100000; ++i) {
    v.push_back(i);
  }
  std::cout << *it << std::endl;

}
