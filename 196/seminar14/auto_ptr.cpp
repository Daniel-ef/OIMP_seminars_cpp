#include <iostream>

template <typename T>
class AutoPtr {
public:
  explicit AutoPtr(T* other) : ptr_(other) {
    std::cout << "Called ctor" << std::endl;
  }

  AutoPtr(AutoPtr<T>& other) {
    ptr_ = other.ptr_;
    other.ptr_ = nullptr;
  }

  ~AutoPtr() {
    std::cout << "Called dtor" << std::endl;
    delete ptr_;
  }

  T& operator*() const {
    return *ptr_;
  }

  T* operator->() const {
    return ptr_;
  }
private:
  T* ptr_;
};

template <typename T>
void print_value(AutoPtr<T> auto_ptr) {
  std::cout << *auto_ptr << std::endl;
}

int main() {
  int* i_ptr = new int(5);
  AutoPtr<int> auto_ptr(i_ptr);
  print_value(auto_ptr);

  AutoPtr<int> another_ptr(auto_ptr);
  print_value(another_ptr);
//  if (*i_ptr) {
//    return 0;
//  }
}
