#include <iostream>
#include <vector>

int main() {
  {
    int a, b;
//    std::cin >> a;
//    std::cin >> b;
//
//    std::cin >> a >> b;
  }
  {
    int a, b = 0;
  }
  {
    int a;
//    std::cin >> a;
  }
  {
    std::string day;
    if (day == "mon") {}
    if (day == "tue") {}

    if (day == "mon") {
    } else if (day == "tue") {}

//    if (a == 1) {
//
//    }
//    if (a > 0)
  }
  {
    int a = 0;

//    int a;
//    a = 0;
  }

  std::vector<int> v;
  std::cout << v.size() << " " << sizeof(v) << std::endl;

  v.push_back(4);
  std::cout << v.size() << " " << sizeof(v) << std::endl;

  std::vector<std::string> days_v{"mon", "tue", "wed"};

  std::vector<int> v1;
  v1.resize(10);

  std::vector<int>v2(10, 2);

  std::vector<std::vector<int>> v22{{0, 0}, {0, 0}};
  std::vector<std::vector<int>> v3(10, std::vector<int>(10, 0));

  size_t rows, cols;
  std::cin >> rows >> cols;
  std::vector<std::vector<int>> v_cin(rows, std::vector<int>(cols));

  for (std::vector<int>& inner_v: v_cin) {
    for (int& el: inner_v) {
      std::cin >> el;
    }
  }

//  for (size_t i = 0; i < rows; ++i) {
//    int el;
//    std::cin >> el;
//    v_cin.push_back(el);
//  }

}
