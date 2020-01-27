#include <iostream>
#include <map>
#include <unordered_map>

struct Student {
  std::string name;
  size_t age;

  //  bool operator()(const Student &st) { return (this->age > st.age); }
};

struct StudentHash {
  size_t operator()(const Student &student) const {
    return std::hash<std::string>()(student.name) ^
           std::hash<size_t>()(student.age);
  }
};

size_t operator==(const Student& lhs, const Student& rhs) {
  return lhs.name == rhs.name && lhs.age == rhs.age;
}

bool operator<(const Student &lhs, const Student &rhs) {
  return lhs.age > rhs.age;
}

int main() {
  std::map<std::string, size_t> ages{
      {"Petya", 30}, {"Vasya", 25}, {"Ivan", 20}};

  //  size_t st = ((size_t)1 << 64) + 1u;
  //  int i = 1 + (1 << 32);
  //  std::cout << st << " " << i << '\n';

  for (const auto &kv : ages) {
    std::cout << kv.first << " " << kv.second << '\n';
  }

  std::unordered_map<size_t, std::string> ages_u{
      {30, "Petya"}, {25, "Vasya"}, {20, "Ivan"}};

  for (const auto &kv : ages_u) {
    std::cout << kv.first << " " << kv.second << '\n';
  }

  std::map<Student, size_t> students{{{"Ivan", 20}, 1}, {{"Olya", 25}, 2}};
  for (const auto &kv : students) {
    std::cout << kv.first.name << " " << kv.first.age << " " << kv.second
              << '\n';
  }

  std::unordered_map<Student, size_t, StudentHash> students_u{{{"Ivan", 20}, 1},
                                                            {{"Olya", 25}, 2}};
  for (const auto &kv : students_u) {
    std::cout << kv.first.name << " " << kv.first.age << " " << kv.second
              << '\n';
  }
}
