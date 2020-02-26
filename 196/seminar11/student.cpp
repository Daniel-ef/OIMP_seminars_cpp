#include <iostream>
#include "student.hpp"

void print_student(Student s) {
  std::cout << s.Id() << std::endl;
}

// copy elision
Student MakeStudent() {
  Student s;
  return s;
}

int main() {
  {
    Student s0;
    Student s1{2};

    Student s2{s0};

    const Student s3{std::move(s2)};
    s3.Id();

    print_student(Student{1});

    Student s4 = (s2 = Student{2});
  }

  std::cout << "####\n";
  Student s5 = MakeStudent();
}

