#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
  double x;
  double y;
};

int comp(const Point& lhs, const Point& rhs) {
  return lhs.x < rhs.x;
}

int main() {
  std::vector<Point> points{{2.5, 1.1}, {8.3, 4.0}};

  std::vector<int> v{6, 1, 9, 2};
  std::sort(v.begin(), v.end());
  for (int el : v) {
    std::cout << el << " ";
  }
  std::cout << '\n';
  std::cout << '\n';

  // sort(points, key=lambda point: point.x)
  std::sort(points.begin(), points.end(), comp);

  for (const Point& point : points) {
    std::cout << point.x << " " << point.y << '\n';
  }
}
