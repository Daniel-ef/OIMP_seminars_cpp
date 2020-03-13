#include <iostream>

class AbstractFigure {
public:
  AbstractFigure(size_t id) {
    ++id_;
  }

  virtual double CalcSquare() = 0;
  virtual void FillPerimeter() = 0;

  double perimeter;

private:
  static size_t id_;
};

class Triangle : public AbstractFigure {
public:
  Triangle() : AbstractFigure(0) {}
public:
  double x1, y1;
  double x2, y2;
  double x3, y3;

  void foo() {
    ++perimeter;
  }

  double CalcSquare()  {
    return 0.0;
  }
};

class JsonParseError : public std::exception {

};


struct Response {
  std::string json_response;
  size_t id;
};

struct OrderResponse : Response {
  OrderResponse(const Response& response) {
    throw JsonParseError{};
//    order_id = FetchOrderId();
//    drivers_count = FetchDriversCount();
  }

  std::string order_id;
  size_t drivers_count;
};

int main() {
  Response response{"{'order_id': 'abc', 'drivers_count': 90'}"};

  try {
    OrderResponse order_response = response;
  } catch (const std::logic_error& err) {
    std::cout << "Got error: " << err.what();
  } catch (const std::runtime_error& err) {
    std::cout << "Got runtime_error";
  }
}