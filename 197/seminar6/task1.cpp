#include <iostream>
#include <unordered_map>

int main() {
  size_t n;
  std::cin >> n;
  std::unordered_map<std::string, std::string> tree;
  std::unordered_map<std::string, size_t> depths;
  size_t max_depth = 0;

  for (size_t i = 0; i < n; ++i) {
    std::string src, dst;
    std::cin >> src >> dst;
    tree[dst] = src;
    if (tree.find(src) == tree.end()) {
      depths[src] = 0;
    }
    depths[dst] = depths[src] + 1;
  }

  std::string name = std::max_element(
      depths.begin(), depths.end(),
      [](const auto& [k2, v1], const auto& [k2, v2]) {
        return v1 < v2;
      })->first;

  while(tree.find(name) != tree.end()) {
    name = tree[name];
  }
  std::cout << name << " " << depths[name] << std::endl;
}
