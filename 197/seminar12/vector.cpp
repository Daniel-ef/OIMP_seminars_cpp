#include <cstdio>
#include <cstring>
#include <initializer_list>
#include <iostream>
#include <stdexcept>

template <typename T> class Vector {
public:
  // ctor
  Vector() = default;

  Vector(const Vector &other)
      : size_(other.Size()), capacity_(other.Capacity()) {
    std::memcpy(data_, other.data_, other.Size());
  }

  Vector(Vector &&other) : size_(other.Size()), capacity_(other.Capacity()) {
    data_ = other.data_;
    other.data_ = nullptr;
  }

  Vector &operator=(const Vector &other) {
    size_ = other.Size();
    capacity_ = other.Capacity();
    std::memcpy(data_, other.data_, other.Size());
  }

  Vector &operator=(Vector &&other) {
    size_ = other.Size();
    capacity_ = other.Capacity();

    data_ = other.data_;
    other.data_ = nullptr;
  }

  explicit Vector(size_t size) : size_(size), capacity_(size) {
    data_ = new T[size];
  }

  Vector(size_t size, T default_value) : Vector(size) {
    for (size_t i = 0; i < size; ++i) {
      data_[i] = default_value;
    }
  }

  explicit Vector(const std::initializer_list<T> init) : Vector(init.size()) {
    // TODO: memcpy
    for (size_t i = 0; i < size_; ++i) {
      data_[i] = init[i];
    }
  }

  // dtor
  ~Vector() { delete[] data_; }

  // Access
  T &operator[](size_t i) { return data_[i]; }

  const T &operator[](size_t i) const { return data_[i]; }

  T &At(size_t i) {
    if (i >= size_) {
      throw std::out_of_range("i >= size");
    }
    return data_[i];
  }

  const T &At(size_t i) const { return const_cast<Vector<T>>(this).at(i); }

  T *Data() const { return data_; }

  // Capacity

  size_t Size() const { return size_; }

  size_t Capacity() const { return capacity_; }

  bool Empty() const { return size_ == 0; }

  void reserve(size_t new_cap) {
    if (new_cap <= capacity_)
      return;

    T *new_data = new T[new_cap];
    std::memcpy(new_data, data_, size_);

    delete[] data_;
    data_ = new_data;
    capacity_ = new_cap;
  }

  // Modifiers

  void clear() {
    size_ = 0;
    for (size_t i = 0; i < size_; ++i) {
      data_[i]->~T();
    }
  }

  void push_back(const T &el) {
    if (size_ == capacity_) {
      reserve(capacity_ * 2);
    }
    data_[size_] = el;
    ++size_;
  }

  void push_back(T &&el) {
    if (size_ == capacity_) {
      reserve(capacity_ * 2);
    }

    data_[size_] = el;
    ++size_;
  }

  template <class... Args>
  T& emplace_back(Args &&... args) {
    if (size_ == capacity_) {
      reserve(capacity_ * 2);
    }

    //    *(data_ + size_) // data_[size_]
    data_[size_]->T(std::forward<Args>(args)...);
  }

private:
  T *data_;
  size_t size_;
  size_t capacity_;
};

struct St {
  int a;
  int b;
};

int main() {
  Vector<St> v(2);
//  v.emplace_back(2, 3);
//  v.emplace_back(3, 4);
//  v.emplace_back(4, 5);
//  for (size_t i = 0; i < v.Size(); ++i) {
//    std::cout << v[i].a << std::endl;
//  }
  (void*)(&v);
}