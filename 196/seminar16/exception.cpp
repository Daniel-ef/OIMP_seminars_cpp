#include <iostream>

class JsonParseError : public std::runtime_error {
public:
  explicit JsonParseError(const std::string& msg)
    : std::runtime_error(msg) {}
};

void ParseJson() {
  throw JsonParseError("unexpected token {");
}

struct A {
  void f() const { std::cout << "A::f()\n"; }
};
struct B: public A {
  virtual void f() const { std::cout << "B::f()\n"; }
};

int main() {
  A a = B();
  a.f();
}

//int main() {
//  try {
//    ParseJson();
//  } catch(const JsonParseError& err) {
//    std::cout << "Error while parsing json: " << err.what();
//  }
//}
