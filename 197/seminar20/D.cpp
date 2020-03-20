#include <vector>
#include <iostream>

class Figure {
public:
  virtual double Perimeter() const = 0;
  virtual ~Figure() {}
};

class Triangle : public Figure{
public:
  Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

  double Perimeter() const final {
    return a + b + c;
  }
private:
  double a;
  double b;
  double c;
};

class Rectangle : public Figure {
public:
  Rectangle(double a, double b) : a(a), b(b){}

  double Perimeter() const final {
    return 2 * (a + b);
  }
private:
  double a;
  double b;
};

int main() {
  std::vector<Figure*> figures;

  std::string type;

  while (std::cin >> type) {
    if (type == "Triangle") {
      int a, b, c;
      std::cin >> a >> b >> c;
      figures.push_back(new Triangle(a, b, c));
    } else if (type == "Rectangle") {
      int a, b;
      std::cin >> a >> b;
      figures.push_back(new Rectangle(a, b));
    }
  }

  for (Figure * f : figures)
    std::cout << f->Perimeter() << "\n";

  for (Figure * f : figures)
    delete f;
}

