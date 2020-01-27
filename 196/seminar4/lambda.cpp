#include <iostream>

template <typename T>
void print_vars2(int i, T lambda) {
  lambda(i);
}

template <typename T>
void print_vars(int i, T lambda) {
  print_vars2(i, lambda);
}

auto get_lambda() {
  std::string s{"hello world"};
  std::string s2{"Foo"};

  auto l = [s, s2](int i) {
    std::cout << s << " " << s2 << " " << i << std::endl;
  };

  return l;
}

int main() {

  auto lambda = get_lambda();

  lambda(5);
}
