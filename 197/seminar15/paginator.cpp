#include <iostream>

class Paginator {

};

template <typename ContainerT>
auto make_paginator(const ContainerT& container,
                    size_t page_size) {
  return Paginator(
      container.begin(),
      container.end(),
      page_size
      );
}

int main() {
  auto paginator = make_paginator({1, 2, 3, 4}, 10);

  for (auto page : paginator) {
    for (auto doc : page) {
      std::cout << doc << std::endl;
    }
  }
}