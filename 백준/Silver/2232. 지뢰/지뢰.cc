#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  bool is_boom = false;
  vector<int> results;
  stack<int> stk;
  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p;

    if (stk.empty()) {
      stk.push(p);
      continue;
    }

    int top_p = stk.top();
    if (!is_boom) {
      if (top_p > p) {
        results.push_back(i - 1);
        while (!stk.empty()) {
          stk.pop();
        }
        is_boom = true;
      } else if (top_p == p) {
        results.push_back(i - 1);
        while (!stk.empty()) {
          stk.pop();
        }
      }
      stk.push(p);
    } else {
      if (top_p > p) {
        stk.pop();
        stk.push(p);
      } else {
        stk.push(p);
        is_boom = false;
      }
    }
  }

  if (!is_boom && !stk.empty()) {
    results.push_back(n);
  }

  for (int r : results) {
    cout << r << endl;
  }
  return 0;
}