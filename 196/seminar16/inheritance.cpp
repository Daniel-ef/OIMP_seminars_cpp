#include <iostream>

class AbstractFigure {
public:
  AbstractFigure(size_t id) : id_(id) {}

  virtual void CalcSquare();
  virtual void FillPerimeter();

  size_t angles;

protected:
  double perimeter;
private:
  size_t id_;
};

class Triangle : public AbstractFigure {
public:
  explicit Triangle(size_t id) : AbstractFigure(id) {}

  void FillPerimeter() final {
    perimeter = 0;
  }

protected:
  double x1, y1;
};

class RegularTriangle : public Triangle {
public:
  explicit RegularTriangle(const Triangle& tr) : Triangle(0) {

  }

};

int main() {
  Triangle tr(5);
  tr.angles;

  RegularTriangle rt = tr;
}
