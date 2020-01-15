#include <iostream>
#include <string>

int main() {

  char* hw = "Hello world";

  std::string s = "Hello world!";

  // for char in s:
  //    print(char)

  for (char ch : s) {
    std::cout << ch << " ";
  }

  std::cout << '\n';
  std::cout << s.substr(4, 5) << '\n';
}
