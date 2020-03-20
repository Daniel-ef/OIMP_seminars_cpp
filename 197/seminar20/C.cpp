#include <iostream>
#include <memory>

/*
Constructor(int): 42
Constructor(int): 17
A::foo()
Destructor
Destructor
 */

class A {
public:
  A(int x) {
    std::cout << "Constructor(int): " << x << "\n";
  }
  A(const A&) {
    std::cout << "Copy constructor\n";
  }
  virtual ~A() {
    std::cout << "Destructor\n";
  }
  virtual void foo() const {
    std::cout << "A::foo()\n";
  }
};

class B : public A {
public:
  B() : A(42) {}

  void foo() const final {
    A another_a(17);
    another_a.foo();
  }
};

int main() {
  std::unique_ptr<A> ptr(new B);
  ptr->foo();
}