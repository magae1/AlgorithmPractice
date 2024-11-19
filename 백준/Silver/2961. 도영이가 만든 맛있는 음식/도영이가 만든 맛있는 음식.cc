#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void func(vector<pair<long, long>>& tastes, pair<long, long>& stored_taste,
          int idx, long* result) {
  if (idx >= tastes.size()) {
    if (stored_taste.first != 1 && stored_taste.second != 0) {
      *result = min(*result, abs(stored_taste.first - stored_taste.second));
    }
    return;
  }

  func(tastes, stored_taste, idx + 1, result);
  pair<long, long> new_taste = {stored_taste.first * tastes[idx].first,
                                stored_taste.second + tastes[idx].second};
  func(tastes, new_taste, idx + 1, result);
}

int main() {
  int n;
  cin >> n;
  vector<pair<long, long>> tastes(n);
  for (int i = 0; i < n; i++) {
    pair<long, long> taste;
    cin >> taste.first >> taste.second;
    tastes[i] = taste;
  }

  long result = LONG_MAX;
  pair<long, long> taste = {1, 0};
  func(tastes, taste, 0, &result);

  cout << result << endl;
  return 0;
}