#include <iostream>
#include <vector>

template <typename IterT>
class Paginator {
public:
  class PageIterator {

  };

  Paginator(const IterT& begin, const IterT& end, size_t page_size) :
  begin_(begin), end_(end), page_size(page_size) {}

  PageIterator begin() {
    return PageIterator(begin_, begin_ + page_size);
  }

  PageIterator end() {
    return PageIterator(end_, end_);
  }

  operator++() {
    ++cur_page;
  }
private:
  IterT begin_;
  IterT end_;
  size_t page_size;
  size_t cur_page{0};
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
  auto container = std::vector<int>{1, 2, 3, 4};
  auto paginator = make_paginator(container, 2);

  for (auto row : paginator) {
    for (auto element : row) {
      std::cout << element << std::endl;
    }
  }
}