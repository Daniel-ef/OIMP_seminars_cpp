#include <iostream>
#include <vector>

template <typename IterT>
class Paginator {
public:
  class PageIterator {
    begin()
    end()

    operator* () {
      return *this;
    }
  };

  Paginator(IterT begin, IterT end, size_t) {}

  PageIterator begin() {
    return PageIterator(begin_, begin_ + page_size_)
  }

  PageIterator end() {
    return PageIterator(end_, end);
  }


private:
  IterT begin_;
  IterT end_;
  size_t page_size_;
//  size_t cur_page_{0};
  IterT cur_iterator;
};

template <typename ContainerT>
auto make_paginator(const ContainerT& container, size_t page_size) {
  return Paginator{container.begin(), container.end(), page_size};
}

int main() {
  auto vec = std::vector<int>{1, 34, 1, 234};

  auto pages = make_paginator(vec, 10);

  for (auto page_it = pages.begin(); page_it != pages.end(); ++page_it) {
    auto page = *page_it;
    for (auto it = page.begin(); it != pages.end(); ++it) {
      *it
    }

  }

  for (auto page : pages) {
    for (auto doc : page) {
      std::cout << doc;
    }
  }
}
