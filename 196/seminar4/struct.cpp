#include <iostream>

struct Point {
  double x;
  double y;
  double z;
};

Point sum_points(const Point& point1, const Point& point2) {
//  Point point;
//  point.x = point1.x + point2.x;
//  point.y = point1.y + point2.y;
//  return point;

  return {point1.x + point2.x, point1.y + point2.y};
}

int main() {
//  std::pair<double, double> point{4.5, 2.5};
//  std::tuple<double, double, double> point3;

  Point point{5.4, 1.2};
  std::cout << point.x << " " << point.y << std::endl;


}
