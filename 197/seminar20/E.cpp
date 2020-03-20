#include <iostream>

// 25 50 44 46 - pdf
// FF D8 FF - jpg
// 50 4B - zip

bool check_numbers(uint32_t x, uint32_t y, size_t size) {
  size_t size1 = 4 - size;
  x = (x >> (size1 * 8));
  return x == y;
}

std::string DetectType(const unsigned char* data, size_t size) {
  uint32_t code = 0;
  for (size_t i = 0; i < size && i < 4; ++i) {
    code <<= 8;
    code += data[i];
  }

  if (size >= 2 && check_numbers(code, 0x404B, 2)) {
    return "zip";
  } else if (size >= 3 && check_numbers(code, 0xffd8ff, 3)) {
    return "jpg";
  } else if (size >= 4 && check_numbers(code, 0x25504446, 4)) {
    return "pdf";
  } else {
    return "other";
  }
}


int main() {
  const unsigned char data[] {0x25, 0x50, 0x44, 0x46, 0x5f};
  std::cout << DetectType(data, 5) << std::endl;

  const unsigned char data1[] {0xff, 0xd8, 0xff, 0x46, 0x5f};
  std::cout << DetectType(data1, 5) << std::endl;

  const unsigned char data2[] {0x40, 0x4b, 0xff, 0x46, 0x5f};
  std::cout << DetectType(data2, 5) << std::endl;

  const unsigned char data3[] {0x1f, 0xd8, 0xff, 0x46, 0x5f};
  std::cout << DetectType(data3, 5) << std::endl;
}