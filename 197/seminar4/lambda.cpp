#include <iostream>

template <typename T>
void print_string_and_int2(int i, T lambda) {
  lambda(i);
}

template <typename T>
void print_string_and_int(int i, T lambda) {
  i += 10;
  print_string_and_int2(i, lambda);
}

auto get_lambda() {
  std::string s("hello_world");
  std::string s2{"Mama"};

  auto l = [s, &s2](int i) mutable {
    s += " myla ramu";
    std::cout << s << " " << s2 << " " << i << std::endl;
  };

  [s, &s2]() {
    return 5;
  }

  return l;
}

int main() {
//  std::string s("hello_world");
//  std::string s2{"Mama"};
//  std::string s1 = "hello_world";
//  std::string s3(5, 'a');
//
  auto lambda = get_lambda();
  lambda(5);

}

