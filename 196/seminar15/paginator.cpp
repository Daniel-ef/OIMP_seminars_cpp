#include <iostream>
#include <vector>

template <typename IterT>
class Paginator {


};

template <typename ContainerT>
Paginator make_paginator(const ContainerT& container, size_t page_size) {
  return Paginator{container.begin(), container.end(), page_size};
}

int main() {
  auto vec = std::vector<int>{1, 34, 1, 234};

  auto pages = make_paginator(vec, 10);

  for (auto page : pages) {
    for (auto doc : page) {
      std::cout << doc;
    }
  }
}
