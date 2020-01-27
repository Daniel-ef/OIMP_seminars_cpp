#include <iostream>

struct string_view {
  const std::string& s;
  size_t start;
  size_t end;
};

int main() {
  std::string s = "hello world";
  std::string s2("hello_world");
  std::string s1{"hello_world"};

  s.substr(0, 5); // hello

  std::string_view sv = s;
  sv.substr(2, 5);
}
