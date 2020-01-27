#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{1, 2, 3};

//  std::cout << v[5] << std::endl;
  std::cout << v.at(5) << std::endl;

  std::string s = "hello world";
  std::string_view sv = s;

  s.substr(2, 5); // generate new object

  sv.substr(2, 5);  // referense to substr
}
