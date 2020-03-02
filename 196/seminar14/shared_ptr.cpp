#include <iostream>

class C {
public:
  C(int i) : i(i) {
    std::cout << "ctor" << std::endl;
  }

  ~C() {
    std::cout << "dtor" << std::endl;
  }
private:
  int i;
};

struct Deleter {
  void operator()(C* c) const {
    std::cout << "Call deleter" << std::endl;
    c->~C();
  }
};

int main() {
  std::shared_ptr<C> shared_ptr{new C{1}, Deleter()};
  std::cout << shared_ptr.use_count() << std::endl;

  {
    std::shared_ptr<C> another_ptr{shared_ptr};
    std::cout << shared_ptr.use_count() << std::endl;
  }

  std::cout << shared_ptr.use_count() << std::endl;

  auto shared = std::make_shared<C>(5);
//  std::make_unique()
}
