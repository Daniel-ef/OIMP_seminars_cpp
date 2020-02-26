#include <iostream>
#include <vector>
#include "c.h"

C makeC() {
  C c1;
  C c2;
  return std::move(c2);
}

struct Student {
  std::string name;
  int age;
};

int main() {
  C c3 = makeC();
//  std::move();
  C c4 = C{std::move(c3)};

  std::vector<Student> v_student;
  v_student.push_back(Student{"Vasya", 20});
  v_student.emplace_back(std::string("Vasya"), 20);

  std::vector<C> v;
  v.emplace_back();

  int stack_i = 5;

  int* heap_i = new int;
  *heap_i = 5;
  delete heap_i;

  int* dynamic_massive = new int[5];
  dynamic_massive[1] = 5;
  delete[] dynamic_massive;
}