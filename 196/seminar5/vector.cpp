#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{1};
  std::cout << v.capacity() << std::endl;
  auto it = v.begin();
  for (size_t i = 0; i < 10; ++i) {
    v.push_back(i);
  }
  std::cout << *it << std::endl;
}
