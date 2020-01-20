#include <iostream>

//struct Point {
//  double x;
//  double y;
//};

int main() {
  std::tuple<int, double, std::string, bool> tp{4, 2.5, "abc", true};
  int a = std::get<0>(tp);

  std::pair<int, bool> pr(1, false);
  int first = pr.first;
  bool second = pr.second;

}
