#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  vector<int> profits(n + 1, 0);

  short t, p;
  for (int i = 1; i <= n; i++) {
    cin >> t >> p;

    profits[i] = max(profits[i - 1], profits[i]);

    int end = i + t - 1;
    if (end <= n) {
      profits[end] = max(profits[end], profits[i - 1] + p);
    }
  }

  cout << profits[n] << '\n';
  return 0;
}