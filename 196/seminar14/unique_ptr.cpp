#include <iostream>

template <typename T>
class UniquePtr {
public:
  explicit UniquePtr(T* other) : ptr_(other) {
    std::cout << "Called ctor" << std::endl;
  }

  UniquePtr(const UniquePtr<T>&) = delete;
  UniquePtr<T>& operator=(const UniquePtr<T>&) = delete;

  UniquePtr(UniquePtr<T>&& other) {
    std::cout << "Called ctor&&" << std::endl;
    ptr_ = other.ptr_;
    other.ptr_ = nullptr;
  }

  UniquePtr<T>& operator=(const UniquePtr<T>&& other) {
    std::cout << "Called operator=&&" << std::endl;
    ptr_ = other.ptr_;
    return *this;
  }

  ~UniquePtr() {
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
UniquePtr<T>&& print_value(UniquePtr<T>&& unique_ptr) {
  std::cout << *unique_ptr << std::endl;
  return std::move(unique_ptr);
}

int main() {
  int* i_ptr = new int(5);
  UniquePtr<int> unique_ptr(i_ptr);
  unique_ptr = print_value(std::move(unique_ptr));

  UniquePtr<int> another_ptr(std::move(unique_ptr));
//  print_value(another_ptr);

//  if (*i_ptr) {
//    return 0;
//  }
}
