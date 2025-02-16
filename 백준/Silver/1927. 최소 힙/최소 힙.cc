#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  priority_queue<int, vector<int>, greater<int>> priority_qu;

  while (n--) {
    int x;
    cin >> x;

    if (x > 0) {
      priority_qu.push(x);
    } else {
      if (priority_qu.empty()) {
        cout << "0" << '\n';
        continue;
      }

      int front = priority_qu.top();
      priority_qu.pop();
      cout << front << '\n';
    }
  }

  return 0;
}