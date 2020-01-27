#include <iostream>


struct Point {
  double x;
  double y;
};

struct Person {
  int age;
  double height;
  std::string name;

  int GetAge() {
    return age;
  }
};

Point sum_point(const Point& p1, const Point& p2) {
//  Point point;
//  point.x = p1.x + p2.x;
//  point.y = p1.y + p2.y;
//  return point;

  return {p1.x + p2.x, p1.y + p2.y};
}

int main() {
  struct Point point{2.5, 1.8};
  std::cout << point.x << " " << point.y << '\n';

  Person person{18, 180.0, "Ivan"};
  std::cout << person.GetAge() << std::endl;

  sum_point(Point{1, 2}, {3, 4});
}