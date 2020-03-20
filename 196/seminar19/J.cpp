#include <iostream>
#include <vector>

int main() {
  std::string line;
  getline(std::cin, line);
  uint64_t num = 0;
  int count = 0;

  for (uint8_t byte : line) {
    uint8_t byte7 = byte & 0b01111111;  // удаляем незначащий страший бит
    uint64_t byte64 = static_cast<uint64_t>(byte) << (7 * count);  // Сдвигаем
    // очередные 7 бит на нужную позицию
    num |= byte64;  // Записываем 7 бит в num с помощью битовго ИЛИ

    ++count;
  }
  std::cout << num;
}
