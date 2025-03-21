#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool check_wifi(vector<int>& houses, int d, int c) {
  bool result = true;
  c -= 1;
  for (int i = 0; i < houses.size() - 1;) {
    int j = i + 1;
    for (; j < houses.size(); j++) {
      if (houses[j] - houses[i] >= d) {
        i = j;
        c--;
        break;
      }
    }
    if (c <= 0) {
      return true;
    }
    if (j == houses.size()) {
      return false;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, c;
  cin >> n >> c;

  vector<int> houses = vector<int>(n);
  for (int i = 0; i < n; i++) {
    cin >> houses[i];
  }
  sort(houses.begin(), houses.end());

  int p, q, d;
  q = houses[n - 1] - houses[0] + 1;
  p = 1;
  while (p < q) {
    d = (p + q) / 2;
    if (p == d || q == d) {
      cout << p << '\n';
      return 0;
    }
    bool is_checked = check_wifi(houses, d, c);
    if (is_checked) {
      p = d;
    } else {
      q = d;
    }
  }

  cout << d << '\n';
  return 0;
}