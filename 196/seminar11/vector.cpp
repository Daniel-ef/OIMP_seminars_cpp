#include <vector>
#include "student.hpp"

int main() {
  std::vector<Student> v;
  v.reserve(3);
  v.push_back(Student{3});

  v.emplace_back(5);
}

