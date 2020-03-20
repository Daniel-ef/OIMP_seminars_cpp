#include <iostream>

char * strcat(char * destination, const char * source) {
  char* cur_sumbol = destination;
  while (*cur_sumbol != '\0') { ++cur_sumbol; }

  for (size_t i = 0; source[i] != '\0'; ++i) {
    *(cur_sumbol++) = source[i];
  }
  *cur_sumbol = '\0';
  return destination;
}

int main() {
  char* s1 = new char[20];

  auto s2 = "Hello ";
  auto s3 = "world";

  std::cout << strcat(strcat(s1, s2), s3) << std::endl;
  assert(strcmp(strcat(strcat(s1, s2), s3), "Hello world"));
}

//~TreeNode() {
//  for (const auto& child : children) {
//    delete child;
//  }
//}