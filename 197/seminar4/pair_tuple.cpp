#include <iostream>


int main() {
  std::tuple<int, char, bool, std::string> tp{1, 'h', true, "mama"};
  std::cout << std::get<3>(tp) << std::endl;

  std::pair<int, char> pr{1, 'h'};
  std::cout << pr.first << " " << pr.second << '\n';

  // ----------------- Structs
}
