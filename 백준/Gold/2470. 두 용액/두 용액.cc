#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<int> potions(n);
  for (int i = 0; i < n; i++) {
    cin >> potions[i];
  }
  sort(potions.begin(), potions.end());

  int closest_sum = INT_MAX;
  int p, q, l, r;
  p = 0, q = n - 1;
  l = p, r = q;
  while (p < q) {
    int sum = potions[p] + potions[q];

    if (abs(sum) < closest_sum) {
      l = p, r = q;
      closest_sum = abs(sum);
    }

    if (sum < 0) {
      p += 1;
    } else if (sum > 0) {
      q -= 1;
    } else {
      break;
    }
  }

  cout << potions[l] << ' ' << potions[r] << '\n';
  return 0;
}