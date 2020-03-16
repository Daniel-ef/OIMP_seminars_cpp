#include <iostream>

int main() {
  unsigned int i = 0x12a5c84d; // little endian
  unsigned int* i_ptr = &i;

  auto i_char_ptr = reinterpret_cast<unsigned char*>(i_ptr);
  for (size_t iter = 0; iter < sizeof(i); ++iter) {
    std::cout << std::hex <<
      static_cast<unsigned int>(i_char_ptr[iter]);
    // *(i_char_ptr + iter)
  }
}
