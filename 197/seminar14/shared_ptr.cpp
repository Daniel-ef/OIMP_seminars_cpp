#include <iostream>

class C {
public:
  C() {
    std::cout << "ctor" << std::endl;
  }

  ~C() {
    std::cout << "dtor" << std::endl;
  }
};

struct D {
  void operator()(C* p) const {
    std::cout << "Call delete for Foo object...\n";
    p->~C();
  }
};

int main() {
  std::shared_ptr<C> shared_ptr(new C, D());
  std::cout << shared_ptr.use_count() << std::endl;

  {
    std::shared_ptr<C> new_shared_ptr(shared_ptr);
    std::cout << new_shared_ptr.use_count() << std::endl;
  }
  std::cout << shared_ptr.use_count() << std::endl;
}