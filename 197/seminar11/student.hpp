#include <iostream>

class Student {
public:
//  def __init__(self, id, counter)

// default ctor
  Student() {
    id_ = counter_++;
    std::cout << "ctor: 1 id: " << id_ << std::endl;
  }


  explicit Student(size_t id) : id_(id) {
    std::cout << "ctor: 2 id: " << id_ << std::endl;
  }

// l-value reference
  Student(const Student& student) : id_(student.id_ + 1) {
    std::cout << "ctor: 3 id: " << id_ << std::endl;
    ++counter_;
  }

// r-value reference
  Student(Student&& student) : id_(student.id_ + 1) {
    std::cout << "ctor: 4 id: " << id_ << std::endl;
  }

  Student& operator=(const Student& student) {
    id_ = student.id_ + 1;
    ++counter_;
    return *this;
  }

  Student& operator=(Student&& student) {
    id_ = student.id_ + 1;
    ++counter_;
    return *this;
  }


  size_t Id() const {
    return id_;
  }

  ~Student() {
    std::cout << "dtor id: " << id_ << std::endl;
  }

private:
  static size_t counter_;
  size_t id_;
};

size_t Student::counter_ = 0;
