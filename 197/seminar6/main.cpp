#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string s, st;
  getline(cin, s);
  vector<string> v;
  v.resize(0);
  getline(cin, st);
  while (getline(cin, st)) {
    v.push_back(st);
  }
  if (s == "ASCENDING") {
    stable_sort(v.begin(), v.end());
  } else {
    stable_sort(v.rbegin(), v.rend());
  }
  for (size_t i = 0; i < v.size(); ++i) {
    cout << v[i] << '\n';
  }

  return 0;
}
