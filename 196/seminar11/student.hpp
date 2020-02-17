#include <iostream>

class Student {
  // def __init__(self, )
public:
  Student() : id_(counter_++) {
    std::cout << "ctor 0 id: " << id_ << std::endl;
  }

  explicit Student(size_t id) : id_(id) {
    std::cout << "ctor 1 id: " << id_ << std::endl;
  }

  // l-value reference
  Student(const Student& student) :
      id_(student.id_ + 1) {
    ++counter_;
    std::cout << "ctor 2 id: " << id_ << std::endl;
  }

  // r-value reference
  Student(Student&& student) : id_(student.id_ + 1) {
    ++counter_;
    std::cout << "ctor 3 id: " << id_ << std::endl;
  }

  Student& operator=(const Student& student) {
    id_ = student.id_+ 1;
    std::cout << "operator= 4 id: " << id_ << std::endl;
    return *this;
  }

  Student& operator=(Student&& student) {
    id_ = student.id_ + 1;
    std::cout << "operator= 5 id: " << id_ << std::endl;
    return *this;
  }

  ~Student() {
    std::cout << "dtor 3 id: " << id_ << std::endl;
  }

  size_t Id() const {
    return id_;
  }

private:
  static size_t counter_;
  size_t id_;
};

size_t Student::counter_ = 0;
