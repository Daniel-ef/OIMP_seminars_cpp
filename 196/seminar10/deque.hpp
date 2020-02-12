#include <iostream>
#include <vector>

template <typename T, size_t N = 10>
struct Deque {
  void push_front(const T& el) {
    begin_v.push_back(el);
  }
  void push_back(const T& el) {
    end_v.push_back(el);
  }

  void pop_front() {
    begin_v.pop_back();
  }

  void pop_back() {
    end_v.pop_back();
  }

  T front() const {
    return begin_v.back();
  }
  T back() const {
    return end_v.back();
  }

  T& operator[](size_t i) {
    if (i < begin_v.size()) {
      return begin_v[begin_v.size() - i - 1];
    } else {
      return end_v[i - begin_v.size()];
    }
  }

  const T& operator[](size_t i) const {
    return const_cast<Deque<T, N>*>(this)->operator[](i);
  }

  size_t size() const {
    return begin_v.size() + end_v.size();
  }

  std::vector<T> begin_v;
  std::vector<T> end_v;
};

int main() {
  Deque<int> deque;
  deque.push_front(1);
  deque.push_front(2);
  deque.push_back(6);
  deque.push_back(8);

  assert(deque.front() == 2);
  assert(deque.back() == 8);
  assert(deque.size() == 4);

  assert(deque[0] == 2);
  assert(deque[1] == 1);
  assert(deque[2] == 6);
  assert(deque[3] == 8);

  deque.pop_back();
  assert(deque.front() == 2);
  assert(deque.back() == 6);

  deque.pop_front();
  assert(deque.front() == 1);
  assert(deque.back() == 6);
  deque[0] = 10;

  const auto& deque1 = deque;
  assert(deque1[0] == 10);

}
