#include <iostream>
#include <list>

struct Node {
  Node* prev;
  int value;
  Node* next;
};

void reverse_list(Node* start) {
  Node* cur_node = start;
  while (cur_node != nullptr) {
    Node* next = cur_node->next;
    cur_node->next = cur_node->prev;
    cur_node->prev = next;
    cur_node = next;
  }
}

void print_list(Node* start) {
  for (; start != nullptr; start = start->next) {
    std::cout << start->value << " ";
  }
  std::cout << '\n';
}

int main() {
  size_t n = 10;
  Node* start = (Node*)malloc(sizeof(Node));
  Node* prev = nullptr;

  for (size_t i = 0; i < n; ++i) {
    start->prev = prev;
    start->next = nullptr;
    if (start-> prev != nullptr)
      start->prev->next = start;
    start->value = random() % 10;
    prev = start;
  }
  for (; start->prev != nullptr; start = start->prev) {}

  print_list(start);

  reverse_list(start);
  for(; start->prev != nullptr; start = start->prev);

  print_list(start);

}
