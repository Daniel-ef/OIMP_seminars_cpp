#include <iostream>
#include <unordered_set>

struct Logins {
  std::unordered_set<std::string> logins;

  std::pair<bool, std::string> add_login(std::string login) {
    bool b = true;
    for (size_t i = 0;; ++i) {
      auto it_b = logins.insert(login);
      if (it_b.second) {
        return {b, login};
      }
      b = false;
      login += std::to_string(i);
    }
  }
};

int main() {
  Logins logins;
  std::string s;
  while (true) {
    std::cin >> s;
    auto res = logins.add_login(s);
    std::cout << (res.first ? "Inserted login: " : "New login: ") << res.second
              << std::endl;
  }
}
