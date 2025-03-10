#include <iostream>
#include <stack>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  stack<int> stk;

  while (n--) {
    int command, x;

    cin >> command;

    switch (command) {
      case 1:
        cin >> x;
        stk.push(x);
        break;
      case 2:
        if (stk.empty()) {
          cout << -1 << '\n';
          break;
        }
        cout << stk.top() << '\n';
        stk.pop();
        break;
      case 3:
        cout << stk.size() << '\n';
        break;
      case 4:
        if (stk.empty()) {
          cout << 1 << '\n';
          break;
        }
        cout << 0 << '\n';
        break;
      case 5:
        if (stk.empty()) {
          cout << -1 << '\n';
          break;
        }
        cout << stk.top() << '\n';
        break;
      default:
        break;
    }
  }

  return 0;
}