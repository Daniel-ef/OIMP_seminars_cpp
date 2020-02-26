#include <vector>
#include "student.hpp"

int main() {
  std::vector<Student> v;
  v.reserve(3);
  v.push_back(Student{3});

  v.emplace_back(5);
  (void*)v[0].Id();
}

