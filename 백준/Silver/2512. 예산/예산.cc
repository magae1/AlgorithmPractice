#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n;

  vector<int> budgets(n);
  for (int i = 0; i < n; i++) {
    cin >> budgets[i];
  }
  cin >> m;

  int cur_budgets = 0;
  int i = 0;
  sort(budgets.begin(), budgets.end());

  for (; i < n; i++) {
    int expected_budgets = cur_budgets + (n - i) * budgets[i];

    if (expected_budgets <= m) {
      cur_budgets += budgets[i];
    } else {
      break;
    }
  }

  if (i < n) {
    int rest_budgets = m - cur_budgets;
    cout << rest_budgets / (n - i) << '\n';
  } else {
    cout << budgets[i - 1] << '\n';
  }

  return 0;
}