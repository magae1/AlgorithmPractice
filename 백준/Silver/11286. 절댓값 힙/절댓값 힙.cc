#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  auto cmp = [](int a, int b) {
    if (abs(a) == abs(b)) {
      return a > b;
    }
    return abs(a) > abs(b);
  };
  priority_queue<int, vector<int>, decltype(cmp)> p_qu(cmp);

  int n;
  cin >> n;
  while (n--) {
    int input;
    cin >> input;

    if (input == 0) {
      if (p_qu.empty()) {
        cout << 0 << '\n';
      } else {
        cout << p_qu.top() << '\n';
        p_qu.pop();
      }
      continue;
    }
    p_qu.push(input);
  }

  return 0;
}