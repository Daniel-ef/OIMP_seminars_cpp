#include <iostream>
#include <cassert>
#include <stdexcept>
#include <sstream>

#define MY_MAIN int main()
#define RETURN return 0
#define ull unsigned long long

using ull1 = unsigned long long;

#define MY_ASSERT(x, y)                              \
  if (x != y) {                                      \
    std::stringstream ss;                            \
    ss << "( " << #x << " == " << #y << " ) ";       \
    ss << #x << " = " << x << ", " << #y << " = " << y; \
    ss << " " << __PRETTY_FUNCTION__  << " "          \
    << __FILE_NAME__ << ":" << __LINE__;              \
    throw std::runtime_error(ss.str());              \
  }

#define SQR(x) ((x) * (x))
#define MY_MAX(x, y) ((x) > (y) ? (x) : (y))

#define PRINT_VALUES(out, x, y) \
  out << x << std::endl,  \
  out << y << std::endl

MY_MAIN {
  int x = 2;
  int y = 4;
//  MY_ASSERT(x, y);
//  std::cout << SQR(y) << std::endl;
//  std::cout << MY_MAX(x, y + 1) << std::endl;

  if (false)
    PRINT_VALUES(std::cout, x, y);
  else
    PRINT_VALUES(std::cout, x + 1, y);

  RETURN;
}