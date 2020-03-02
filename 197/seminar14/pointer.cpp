#include <iostream>

template <typename T>
class AutoPtr {
public:
  explicit AutoPtr(T* ptr) : ptr_(ptr) {
    std::cout << "Called ctor*" << std::endl;
  }

  ~AutoPtr() {
    std::cout << "Called dtor" << std::endl;
    delete ptr_;
  }

  explicit AutoPtr(AutoPtr<T>& other) {
    std::cout << "Called ctor&" << std::endl;
    ptr_ = other.ptr_;
    other.ptr_ = nullptr;
  }

  AutoPtr<T>& operator=(AutoPtr<T>& other) {
    std::cout << "Called =" << std::endl;
    ptr_ = other.ptr_;
    other.ptr_ = nullptr;
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
class UniquePtr {
public:
  explicit UniquePtr(T* ptr) : ptr_(ptr) {
    std::cout << "Called ctor*" << std::endl;
  }

  ~UniquePtr() {
    std::cout << "Called dtor" << std::endl;
    delete ptr_;
  }

  UniquePtr(const UniquePtr<T>& other) = delete;

  UniquePtr<T>& operator=(const UniquePtr<T>& other) = delete;

  UniquePtr(UniquePtr<T>&& other) {
    std::cout << "Called ctor&&" << std::endl;
    ptr_ = other.ptr_;
    other.ptr_ = nullptr;
  }

  UniquePtr<T>& operator=(UniquePtr<T>&& other) {
    std::cout << "Called =&&" << std::endl;
    ptr_ = other.ptr_;
    other.ptr_ = nullptr;
    return *this;
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


// std::auto_ptr (deprecated)
template <typename T>
UniquePtr<T>&& print_ptr(UniquePtr<T>&& ptr) {
  std::cout << *ptr << std::endl;
  return std::move(ptr);
}

int main() {
  int *i_ptr = new int;

  UniquePtr<int> unique_ptr(i_ptr);
  unique_ptr = print_ptr(std::move(unique_ptr));

  UniquePtr<int> another_unique_ptr(std::move(unique_ptr));

  another_unique_ptr = print_ptr(std::move(another_unique_ptr));
}
