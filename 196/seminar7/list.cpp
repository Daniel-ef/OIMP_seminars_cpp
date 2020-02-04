#include <iostream>
#include <list>

// #1
struct Node {

};

void reverse_list(Node* start) {
  Node* node = malloc(sizeof(Node));
}

// #2

void unite_lists(std::list<int>& dst, const std::list<int>& src);

int main() {
  std::list<int> l{5, 2, 9};

  auto it = l.begin();
  std::advance(it, 2);

  auto it1 = std::next(it, 5);

  std::distance(l.begin(), l.end());
  l.size();

  l.insert(it, 10);

  for (const auto& el : l) {
    std::cout << el << std::endl;
  }

  l.erase(it);
  l.push_front(1);
  l.push_back(5);

}
