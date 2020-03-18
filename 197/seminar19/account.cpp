#include <iostream>
#include <future>
#include <vector>

struct Account {
  int value{0};
  std::vector<int> history;
  std::mutex m;  // mutual exclusion

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

size_t SpendMoney(Account& account, size_t amount) {
  size_t total_spend = 0;
  for (size_t i = 0; i < amount; ++i) {
    total_spend += account.Spend(1);
  }
  return total_spend;
}

int main() {
  int total_amount = 100000;
  Account account{total_amount};

  std::future<size_t> father = std::async(SpendMoney, std::ref(account),
      total_amount);
  std::future<size_t> mother= std::async(SpendMoney, std::ref(account),
                                                total_amount);
  std::future<size_t> brother= std::async(SpendMoney, std::ref(account),
                                                 total_amount);
  std::future<size_t> sister= std::async(SpendMoney, std::ref(account),
                                                total_amount);

  size_t total_spend = father.get() + mother.get() + brother.get() + sister
      .get();
  std::cout << total_spend << std::endl;
  std::cout << account.value << std::endl;
}