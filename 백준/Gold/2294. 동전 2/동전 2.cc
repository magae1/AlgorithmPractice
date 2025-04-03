#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  cin >> n >> k;

  vector<int> coins(k + 1, 0);
  while (n--) {
    int c;
    cin >> c;
    if (c <= k) {
      coins[c] = 1;
    }
  }

  for (int i = 1; i <= k; i++) {
    if (coins[i] == 1) continue;

    for (int j = 1; j <= i / 2; j++) {
      if (coins[j] == 0) continue;
      if (coins[i - j] == 0) continue;

      if (coins[i] == 0) {
        coins[i] = coins[j] + coins[i - j];
      } else {
        coins[i] = min(coins[i], coins[j] + coins[i - j]);
      }
    }
  }

  if (coins[k] == 0) {
    cout << -1 << '\n';
  } else {
    cout << coins[k] << '\n';
  }
  return 0;
}