#include <iostream>

// vector<int>::iterator

template <typename T>
class Vector {
public:
  using value_type = T;
  // ctor
  Vector() = default;

  Vector(const Vector<T> &other) : Vector(other.size_) {
    std::memcpy(data_, other.data_, size_ * sizeof(T));
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
    std::memcpy(data_, other.data_, size_ * sizeof(T));
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
    for (size_t i = 0; i < size_; ++i, ++it) {
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
    std::memcpy(new_data, data_, size_ * sizeof(T));
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

  // iterator

  class Iterator {
  public:
    // needs for std::distance, std::next
    using difference_type = size_t;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using iterator_category = std::random_access_iterator_tag;

    Iterator() = default;
    explicit Iterator(T* ptr) : ptr(ptr) {}

    T& operator*() {
      return *ptr;
    }

    // ptr->a
    T* operator->() {
      return ptr;
    }

    Iterator& operator++() {
      ++ptr;
      return *this;
    }

    Iterator& operator--() {
      --ptr;
      return *this;
    }

    bool operator==(Iterator other) {
      return this->ptr == other.ptr;
    }

    bool operator!=(Iterator other) {
      return !(*this == other);
    }

    Iterator operator+(int i) {
      return Iterator(ptr + i);
    }

    size_t operator-(const Iterator& other) {
      return std::abs(ptr - other.ptr);
    }

  private:
    T* ptr;
  };

  Iterator begin() const {
    return Iterator(data_);
  }

  Iterator end() const {
    return Iterator(data_ + size_);
  }

  Iterator insert(Iterator it, const T& value) {
    size_t pos_it = it - this->begin();
    this->push_back(0);

    for (size_t i = size_ - 1; i > pos_it; --i) {
      data_[i] = data_[i - 1];
    }

    data_[pos_it] = value;

    return Iterator(data_ + pos_it);
  }

  Iterator erase(Iterator first, Iterator last) {
    Iterator ret = first;
    for (auto it = last; it != this->end(); ++it) {
      *first = *it;
      ++first;
    }
    size_ -= ret - last;

    return ret;
  }

  Iterator erase(Iterator it) {
    return this->erase(it, it + 1);
  }

private:
  size_t size_{0};
  size_t capacity_{0};
  T* data_;
};

int main() {
  Vector<int> v({1, 2});
  v.push_back(3);
  v.emplace_back(4);

  v.insert(v.begin() + 1, 9);

  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  for (auto el : v) {
    std::cout << el << " ";
  }
  std::cout << std::endl;

  auto it = v.erase(v.begin() + 1, v.begin() + 3);
  std::copy(v.begin(), v.end(), // decltype - get type of variable
            std::ostream_iterator<decltype(v)::value_type>(std::cout, " "));
  std::cout << std::endl;
  std::cout << *it << std::endl;

  std::cout << std::distance(v.begin(), v.end()) << std::endl;
  std::cout << *std::next(v.begin(), 1) << std::endl;


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