#include <iostream>
#include <set>
#include <unordered_set>

int main() {
  std::set<int> s{6, 2, 4, 2};
  std::unordered_set<int> us{6, 2, 4, 2};

  auto it_find = s.find(2);
  int el_find = *it_find;

  std::pair<std::set<int>::const_iterator, bool> res = s.insert(5);
  std::cout << *res.first << " " << res.second << std::endl;
  res = s.insert(5);
  std::cout << *res.first << " " << res.second << std::endl;

  s.erase(s.find(5));

  for (const int el : s) {
    std::cout << el << '\n';
  }

}
