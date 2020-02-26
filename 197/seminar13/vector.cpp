#include <cstdio>
#include <cstring>
#include <initializer_list>
#include <iostream>
#include <stdexcept>


template <typename T>
class Vector {
public:

  class Iterator {
  public:
    using difference_type = size_t;

    Iterator() = default;
    Iterator(T* ptr) : ptr_(ptr) {}

    // *it = 5;
    T& operator*() {
      return *ptr_;
    }

    const T& operator*() const {
      return *ptr_;
    }

    // it->name = "Vasya";
    T* operator->() {
      return ptr_;
    }

    Iterator& operator++() {
      ++ptr_;
      return *this;
    }

    Iterator& operator--() {
      --ptr_;
      return *this;
    }

    Iterator& operator+(int i) {
      ptr_ += i;
      return *this;
    }

    size_t operator-(Iterator other) {
      return std::abs(ptr_ - other.ptr_);
    }

    bool operator==(Iterator other) {
      return *ptr_ == *other;
    }

    bool operator!=(Iterator other) {
      return !(*this == other);
    }

  private:
    T* ptr_;
  };
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
    auto it = init.begin();
    for (size_t i = 0; i < size_; ++i, ++it) {
      data_[i] = *it;
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

  T& front() {
    return data_[0];
  }
  const T& front() const {
    return data_[0];
  }

  T& back() {
    return data_[size_ - 1];
  }
  const T& back() const {
    return data_[size_ - 1];
  }

  // Capacity

  size_t Size() const { return size_; }

  size_t Capacity() const { return capacity_; }

  bool Empty() const { return size_ == 0; }

  void reserve(size_t new_cap) {
    if (new_cap <= capacity_)
      return;

    T *new_data = new T[new_cap];
    std::memcpy(new_data, data_, size_ * sizeof(T));

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

    std::allocator<T>{}.construct(
        data_ + size_++,
        std::forward<Args>(args)...);
    return back();
  }

  Iterator insert(Iterator pos, const T& value) {
    size_t pos_i = pos - this->begin();
    this->push_back(0);

    for (size_t i = size_ - 1; i > pos_i; --i) {
      data_[i] = data_[i - 1];
    }

    data_[pos_i] = value;
    return Iterator(data_ + pos_i);
  }

  // Iterators

  Iterator begin() {
    return Iterator(data_);
  }

  Iterator end() {
    return Iterator(data_ + size_);
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
  Vector<int> v({5, 1, 2, 3});

  v.insert(v.begin() + 1, 9);

  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << std::endl;
  }

//  auto it = std::next(v.begin(), 2);
//  std::distance(v.begin(), v.end());
}