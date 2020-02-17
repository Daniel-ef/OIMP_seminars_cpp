#include <iostream>

class Simple {
public:
  Simple() {
    std::cout << "1" << std::endl;
  }

  explicit Simple(size_t count) : id_(count) {
    std::cout << "2" << std::endl;
  }

  Simple(const Simple& simple) : id_(simple.id_) {
    std::cout << "3" << std::endl;
  }

  Simple(Simple&& simple) : id_(simple.id_) {
    std::cout << "3" << std::endl;
  }

  size_t Count() const {
    return id_;
  }

  void Increment() {
    ++id_;
  }

  ~Simple() {
    std::cout << "Dtor " << id_ << std::endl;
  }

  Simple& operator= (const Simple& s) {
    id_ = s.id_;
    return *this;
  }

private:
  size_t id_{0};
};

Simple makeSimple() {
  auto s = Simple{1};
  return s;
}

void print_simple(Simple s) {
  std::cout << "print: " << s.Count() << std::endl;
}


int main() {
  {
    Simple s1;

    const Simple s2{2};

    Simple s3{s2};

    Simple s4{Simple{3}};

  }
  Simple s5 = makeSimple();

  Simple s6 = s5;

  print_simple(5);

//  std::cout << s1.Count() << s2.Count() << s3.Count() << s4.Count() << s5.Count();

}