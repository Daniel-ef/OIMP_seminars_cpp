#include <iostream>
#include "c.h"

C makeC() {
  C c1;
  C c2;
  return c2;
}

int main() {
  C c3 = makeC();

  C c4(std::move(c3));
  C c5(C{});

  int stack_i = 5;

  int* heap_i = new int;
  *heap_i = 5;
  delete heap_i;

  int* heap_massive = new int[6];
  heap_massive[2] = 0;
  delete[] heap_massive;
}
