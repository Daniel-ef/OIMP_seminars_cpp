#include <iostream>
#include "student.hpp"

// copy elision
Student MakeStudent() {
  Student s{1};
  return s;
}

int main() {

  {
    Student s1{2};
    {
      Student s1{1};
      std::cout << s1.Id() << std::endl;
    }
    std::cout << s1.Id() << std::endl;

  }

  Student s1 = MakeStudent();
}
