#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>

/*
 * def print_vector(v: list):
 */
void print_vector(std::vector<int> v) {
  std::numeric_limits<int>::max();

  for (auto el : v) {
    std::cout << el << " ";
  }
  std::cout << std::endl;

  Container::value_type
  std::copy(v.begin(), v.end(),
      std::ostream_iterator<Container::value_type>(std::cout, " "));
}

int main() {
  std::vector<int> v{1, 2, 3};
  v.push_back(4);
//  v.clear();
  v.back(); // last element
  v.front(); // first element

  print_vector(v);

  // Don't do it at home
  for (int* ptr = v.data(); ptr != v.data() + v.size(); ++ptr) {
    std::cout << *ptr << " ";
  }
  std::cout << std::endl;

  for (auto it = v.begin() + 1; it != v.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  for (size_t i = 0; i < v.size(); ++i) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;

}