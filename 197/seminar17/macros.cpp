#include <stdexcept>
#include <sstream>
#include <iostream>

#define MyMain int main()
#define RETURN return 0

#define ASSERT_EQUAL(x, y)              \
{                                       \
  if (x != y) {                         \
  std::stringstream os;                 \
  os << "assert false " << #x << " != " << #y \
  << " " << __FILE__     \
  << ":" << __LINE__ << std::endl;      \
  throw std::runtime_error(os.str());   \
  }                                     \
}

#define MAX(x, y) x > y ? x : y

#define SQUARE(x) (x) * (x)

#define PRINT_VALUES(out, x, y) \
  {out << (x) << std::endl; \
  out << (y) << std::endl;}

MyMain {

  int x = 5;
  int y = 7;
//  ASSERT_EQUAL(x, y);
//  std::cout << MAX(x, y + 5);

//  std::cout << SQUARE(x + 1);

  if (false)
    PRINT_VALUES(std::cout, x, y)
  else
    PRINT_VALUES(std::cout, x, y)

  RETURN;
}
