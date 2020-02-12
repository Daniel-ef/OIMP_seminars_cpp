#include <iostream>
#include <stack>
#include <queue>
#include <deque>

int main() {
  std::stack<int> st;
  st.push(1);
  int el = st.top();
  st.pop();

  std::queue<int> q;
  q.push(1);
  q.front();
  q.back();
  q.pop();

  std::priority_queue<int> pq;
  pq.push(7);
  pq.push(1);
  pq.push(4);
  pq.push(2);
  while (!pq.empty()) {
    std::cout << pq.top() << ' ';
    pq.pop();
  }
  std::cout << std::endl;

  std::deque<int> dq;
}

