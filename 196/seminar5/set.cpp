#include <iostream>
#include <set>
#include <unordered_set>

int main() {
  std::set<int> s{2, 8, 2, 4};
  for (int el : s) {
    std::cout << el << '\n';
  }

  std::pair<std::set<int>::const_iterator, bool> ret = s.insert(5);
  std::cout << *ret.first << " " << ret.second << "\n";

  ret = s.insert(5);
  std::cout << *ret.first << " " << ret.second << '\n';

  s.erase(ret.first);
}
