#include <iostream>
#include <vector>

struct Point {
  double x;
  double y;
};

int comp(const Point& lhs, const Point& rhs) {
  return lhs.x < rhs.x;
}

int main() {
  std::vector<Point> points{{4.0, 1.2}, {1.5, 2.9}};

  std::vector<int> v{8, 1, 2};
  std::sort(v.begin(), v.end());

  std::sort(points.begin(), points.end(),
      [](const Point& lhs, const Point& rhs) {
    return lsh.x < rhs.x;
  });
  for (const Point& point : points) {
    std::cout << point.x << " " << point.y << std::endl;
  }
}
