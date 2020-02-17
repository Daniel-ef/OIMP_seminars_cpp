#include <vector>

template <typename T>
class Deque {
public:
  Deque() = delete;
  Deque(size_t fix_size);
  Deque(size_t fix_size, std::initializer_list<T>&& init);

  Deque(const Deque<T>& other);
  Deque(Deque<T>&& other);

  // operator =

  // push_back, push_front
  // pop_back, pop_front
  // front, back

  // reserve, empty, clear, resize
private:
//  std::vector<std::array<T, N1>> data_;
  std::vector<std::vector<T>> data_;
  size_t shift_;
  size_t size_;
  size_t fix_size_;
};