#include<iostream>
#include<stack>

using namespace std;

int main() {
  stack<int> st;
  string input;
  cin >> input;
  bool broken = false;
  int l;
  l = input.size();
  for (int i = 0; i < l; ++i) {
    if (input[i] == '(')
      st.push(1);
    if (input[i] == ')') {
      if (st.empty()) {
        broken = true;
        cout << "incorrect" << endl;
        break;
      }
      else {
        st.pop();
      }
    }
  }
  if (st.empty() && !(broken)) {
    cout << "correct" << endl;
  }
  else if (!broken) {
    cout << "incorrect" << endl;
  }
}
