#include <iostream>
#include <vector>

int main() {
  std::vector<int> v1{1, 5, 6};
  std::vector<int> v2;
  std::copy(v1.begin(), v1.end(), std::back_inserter(v2));

}