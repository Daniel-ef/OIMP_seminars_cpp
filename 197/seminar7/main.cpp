#include <iostream>
#include <list>

int main() {
  std::list<int> l{5, 1, 2};
  auto it1 = l.begin();
  std::advance(it1, 12); // shift it1
  auto it2 = std::next(l.begin(), 2);
  std::distance(l.begin(), l.end());

  l.insert(it1, 10);
  for (const auto& el: l) {
    std::cout << el << std::endl;
  }

  std::map<int, int> m;
  m.insert({1, 2})
  m[1] = 2;

}