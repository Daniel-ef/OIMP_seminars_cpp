#include <future>
#include <iostream>
#include <vector>

struct Account {
  int value{0};
  std::mutex m;
  std::vector<int> history;

  // mutex - mutual exclusion
  bool Spend(int amount) {
    std::lock_guard<std::mutex> lg(m);
    if (amount <= value) {
      value -= amount;
      history.push_back(amount);
      return true;
    }
    return false;
  }
};

size_t SpendMoney(Account &account) {
  size_t total_spend = 0;
  for (size_t i = 0; i < 100000; ++i) {
    total_spend += account.Spend(1);
  }
  return total_spend;
}

int main() {
  Account account{100000};

  std::future<size_t> father = std::async(SpendMoney, std::ref(account));
  std::future<size_t> mother = std::async(SpendMoney, std::ref(account));
  std::future<size_t> brother = std::async(SpendMoney, std::ref(account));
  std::future<size_t> sister = std::async(SpendMoney, std::ref(account));

  std::cout << father.get() + mother.get() + brother.get() + sister.get()
            << std::endl;
  std::cout << account.value << std::endl;
}
