#include <iostream>
#include <vector>
#include "student.hpp"


void PrintStudent(Student s) {
  std::cout << s.Id() << std::endl;
}

int main() {
//  Student s1;
  Student s2{1};
  const Student s3{s2.Id() + 1};
  Student s4{s3.Id() + 1};


  std::cout << "#####\n";
  Student s5(s4);
  Student s6(Student{1});

  std::cout << s6.Id() << s2.Id() << s3.Id() << s4.Id() << std::endl;

  PrintStudent(Student{5});

  Student s7 = s6;

  Student s8 = Student{9};

  Student s9 = (s8 = Student{9});
//  Student s5{};
}