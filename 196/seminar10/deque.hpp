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


template<typename T>
struct Deque1 {

  T front() const {
    return vec_lst[0][to_push_front + 1];
  }

  T back() const {
    return vec_lst.back()[to_push_back - 1];
  }

  void push_back(const T& elem) {
    if (vec_lst.empty()) {
      std::vector<T> temp(const_size);
      vec_lst.push_back(temp);
      --to_push_front;
      this->push_back(elem);
    } else if (to_push_back < const_size - 1) {
      ++dsize;
      vec_lst.back()[to_push_back] = elem;
      ++to_push_back;
    } else {
      ++dsize;
      vec_lst.back()[to_push_back] = elem;
      to_push_back = 0;
      std::vector<T> temp(const_size);
      vec_lst.push_back(temp);
    }
  }

  void push_front(const T& elem) {
    if (vec_lst.empty()) {
      std::vector<T> temp(const_size);
      vec_lst.push_back(temp);
      ++to_push_back;
      this->push_front(elem);
    } else if (to_push_front > 0) {
      ++dsize;
      vec_lst[0][to_push_front] = elem;
      --to_push_front;
    } else {
      ++dsize;
      vec_lst[0][to_push_front] = elem;
      to_push_front = const_size - 1;
      std::vector<T> temp(const_size);
      vec_lst.insert(vec_lst.begin(), temp);
    }
  }

  void pop_back() {
    if (dsize != 0) {
      --dsize;
      if (to_push_back == 0) {
        to_push_back = const_size - 1;
        vec_lst.pop_back();
      } else {
        --to_push_back;
      }
    }
  }

  void pop_front() {
    if (dsize != 0) {
      --dsize;
      if (to_push_front == const_size - 1) {
        to_push_front = 0;
        vec_lst.erase(vec_lst.begin());
      } else {
        ++to_push_front;
      }
    }
  }

  T operator[] (size_t index) {
    return vec_lst[(to_push_front + 1 + index) / const_size][(to_push_front + 1 + index) % const_size];
  }

  size_t size() {
    return dsize;
  }

  std::vector<std::vector<T>> vec_lst;
  size_t dsize = 0;
  size_t shift = 3, const_size = 10;
  size_t to_push_front = const_size / 2 , to_push_back = const_size / 2;
};

int main() {
  Deque1<int> deque;
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
}
