#include <iostream>
#include <queue>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);

  priority_queue<int> qu;

  int n, x;
  cin >> n;
  while (n--) {
    cin >> x;

    if (x == 0) {
      if (qu.empty()) {
        cout << 0 << '\n';
      } else {
        cout << qu.top() << '\n';
        qu.pop();
      }
      continue;
    }

    qu.push(x);
  }

  return 0;
}