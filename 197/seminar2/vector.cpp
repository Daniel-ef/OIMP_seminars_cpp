#include <iostream>
#include <vector>

/*
 * def print_vector(vec: list) -> bool:
 *
 */
void print_vector(std::vector<int> vec) {
  for (int el: vec) {
    std::cout << el << " ";
  }
  std::cout << '\n';
}

int main() {
  std::vector<int> v;
  v.push_back(1); // python: l = []; l.append(1)
  v.push_back(2);

  print_vector(v);
  v.front();  // first element
  v.back(); // last element

  v.insert(v.begin(), {10, 20, 30});
  v.insert(v.begin(), 100);

  v.pop_back();  // remove from back
  v.erase(v.begin() + 1);

  int* v_ptr = v.data();


  // std::vector<int>::const_iterator -> auto
  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << '\n';

  for (int i = 0; i < v.size(); ++i) {
    std::cout << v[i] << " ";
  }
  std::cout << '\n';

  for (int* ptr = v.data();  ptr != v.data() + v.size(); ++ptr) {
    std::cout << *ptr << " ";
  }
  std::cout << '\n';
}