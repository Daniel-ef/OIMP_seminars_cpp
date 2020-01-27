#include <iostream>
#include <map>
#include <unordered_map>

struct Student {
  std::string name;
  size_t age;
};

struct StudentHash {
  size_t operator()(const Student &student) const {
    return std::hash<std::string>()(student.name) ^
           std::hash<size_t>()(student.age);
  }
};

bool operator==(const Student& lhs, const Student& rhs) {
  return lhs.name == rhs.name && lhs.age == rhs.age;
}

bool operator<(const Student& lhs, const Student& rhs) {
  return lhs.age > rhs.age;
}

int main() {
  std::unordered_map<std::string, size_t> students{{"Ivan", 20}, {"Kolya", 35}};
  size_t age = students["Ivan"];
  //  age = students.at("van");
  auto it = students.find("Ivan");
  if (it != students.end()) {
    std::cout << it->first << " " << it->second << std::endl;
  }

  std::unordered_map<Student, size_t, StudentHash> students1{
      {{"Ivan", 20}, 180},
      {{"Kolya", 30}, 190},
  };
  std::cout << students1[Student{"Ivan", 20}] << std::endl;

  std::map<Student, size_t> students2{
      {{"Ivan", 20}, 180},
      {{"Kolya", 30}, 190},
  };
  for (const auto& el : students2) {
    std::cout << el.first.name << " " << el.second << "\n";
  }
}
