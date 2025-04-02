#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> students(n + 1);
    vector<bool> is_visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
      cin >> students[i];
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
      if (is_visited[i]) continue;

      int cur = i;
      stack<int> stk;
      while (true) {
        if (is_visited[cur]) {
          int tmp = 0;
          while (!stk.empty()) {
            int prev = stk.top();
            stk.pop();
            tmp += 1;

            if (cur == prev) {
              result += tmp;
              break;
            }
          }
          break;
        }

        is_visited[cur] = true;
        stk.push(cur);
        cur = students[cur];
      }

      while (!stk.empty()) {
        stk.pop();
      }
    }
    cout << n - result << '\n';
  }

  return 0;
}