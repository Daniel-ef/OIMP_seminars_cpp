#include <iostream>

template <typename T> class Vector {
public:
  // ctor
  Vector() = default;

  Vector(const Vector<T> &other) : Vector(other.size_) {
    std::memcpy(data_, other.data_, size_);
  }

  Vector(Vector<T> &&other) {
    size_ = other.size_;
    capacity_ = other.capacity_;

    data_ = other.data_;
    other.data_ = nullptr;
  }

  Vector<T> &operator=(const Vector<T> &other) {
    size_ = other.size_;
    capacity_ = other.capacity_;
    std::memcpy(data_, other.data_, size_);
    return *this;
  }

  Vector<T> &operator=(Vector<T> &&other) {
    size_ = other.size_;
    capacity_ = other.capacity_;

    data_ = other.data_;
    other.data_ = nullptr;
    return *this;
  }

  explicit Vector(size_t size) : size_(size), capacity_(size) {
    data_ = new T[size];
  }

  Vector(size_t size, const T &default_value) : Vector(size) {
    for (size_t i = 0; i < size; ++i) {
      data_[i] = default_value;
    }
  }

  // Vector<int> v({1, 2, 3});
  Vector(const std::initializer_list<T> &init) : Vector(init.size()) {
    auto it = init.begin();
    for (size_t i = 0; i < size_; ++i) {
      data_[i] = *it;
    }
  }

  // dtor
  ~Vector() { delete[] data_; }

  // Access

  T &operator[](size_t i) {
    return data_[i]; // *(data + i)
  }

  const T &operator[](size_t i) const { return data_[i]; }

  const T &at(size_t i) const {
    if (i >= size_)
      throw std::out_of_range("i >= size_");

    return data_[i];
  }

  T &at(size_t i) { return const_cast<Vector<T>>(this).at(i); }

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

  size_t size() const { return size_; }

  size_t capacity() const { return capacity_; }

  bool empty() const { return size_ == 0; }

  void reserve(size_t new_cap) {
    if (new_cap <= capacity_)
      return;

    T *new_data = new T[new_cap];
    std::memcpy(new_data, data_, size_);
    delete[] data_;

    capacity_ = new_cap;
    data_ = new_data;
  }

  void resize(size_t new_size) {
    if (new_size < size_) {
      for (size_t i = new_size; i < size_; ++i) {
        data_[i].~T(); // call dtor
      }
      size_ = new_size;
    } else {
      reserve(new_size);
      for (size_t i = size_; i < new_size; ++i) {
        data_[i] = T{};
      }
    }
  }

  // Modifiers

  void clear() { resize(0); }

  void push_back(const T &el) {
    if (size_ == capacity_) {
      reserve(capacity_ * 2);
    }
    data_[size_++] = el;
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

  void pop_back() {
    data_[--size_].~T();
  }

private:
  size_t size_{0};
  size_t capacity_{0};
  T *data_;
};

int main() {
  Vector<int> v({1, 2});
  v.push_back(3);
  v.emplace_back(4);

  assert(v.front() == 1);
  assert(v.back() == 4);
  assert(v.size() == 4);
  assert(v.capacity() == 4);

  v.push_back(5);
  assert(v.size() == 5);
  assert(v.capacity() == 8);

  v.pop_back();
  assert(v.back() == 4);

  v.resize(0);
  assert(v.empty());
}