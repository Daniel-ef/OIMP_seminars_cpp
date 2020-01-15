#include <iostream>
#include <vector>
#include <random>

void print_vector(std::vector<int> vec) {
  for (int el: vec) {
    std::cout << el << " ";
  }
  std::cout << '\n';
}

int main() {
  size_t N = 10;
  std::vector<int> v;
  for (size_t i = 0; i < N; ++i) {
    v.push_back(std::rand() % 10);
  }

  print_vector(v);

  std::vector<std::vector<int>> anses;

  int prev_el = v.front();
  int max_size = 0;
  std::vector<int> current_ans{prev_el};
  
  for (auto it = v.begin() + 1; it != v.end(); ++it) {
    if (*it > prev_el) {
      prev_el = *it;
      current_ans.push_back(*it);
    } else {
      if (current_ans.size() > max_size) {
        max_size = current_ans.size();
        anses.clear();
        anses.push_back(current_ans);
      } else if (current_ans.size() == max_size) {
        anses.push_back(current_ans);
      }

      current_ans.clear();
    }
  }
  
  for (auto ans: anses) {
    print_vector(ans);
  }

}