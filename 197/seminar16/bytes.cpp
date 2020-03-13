#include <iostream>

int main() {
  unsigned int i = 0x120cba4f;

  auto* i_ptr = reinterpret_cast<unsigned char*>(&i);
  for (size_t byte_i = 0; byte_i != sizeof(i); ++byte_i) {
    std::cout << std::hex << (unsigned int)i_ptr[byte_i];
  }
}