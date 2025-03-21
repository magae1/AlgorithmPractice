#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<int> towers(n);
  vector<int> received(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> towers[i];
  }

  stack<pair<int, int>> stk;
  for (int i = n - 1; i >= 0; i--) {
    int cur_tower = towers[i];

    while (!stk.empty()) {
      pair<int, int>& prev_tower = stk.top();
      if (prev_tower.first < cur_tower) {
        received[prev_tower.second] = i + 1;
        stk.pop();
      } else {
        break;
      }
    }
    stk.push(make_pair(cur_tower, i));
  }

  for (int r : received) {
    cout << r << ' ';
  }
  cout << '\n';

  return 0;
}