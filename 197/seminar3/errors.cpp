#include <iostream>
#include <vector>

struct vector {
  int* v_ptr;
  size_t size;
  size_t capacity;
};

int main() {
  {
    int a, b;
//    std::cin >> a;
//    std::cin >> b;
//
//    std::cin >> a >> b;
  }

  // -----------------

  {
    int a = 0;
//    std::cin >> a;
  }

  {
    std::string s;
    if (s == "mon") {

    } else if (s == "tue") {
    }
  }

  {
    // NO
    int a;
    a = 0;

    // Yes
    int b = 0;
  }

  {
    int a, b;
    a = b = 0;
  }

  {
    int i;

    for (i = 0; i < 10; ++i) {

    }

    for (; i < 20; ++i) {}
  }

  {
    std::vector<int> v;
    std::cout << v.size() << " " << sizeof(v) << " " << sizeof(size_t) << '\n';

    v.push_back(4);
  }

  {
    std::vector<std::string> v2{"mon", "tue", "wed"};
  }

  {
    std::vector<int> v(10, 5);
    (void)v;
  }

  {
    int n = 10;
    std::vector<int> v(n);
    for (auto el: v) {
      std::cout << el << " ";
    }
  }

}
