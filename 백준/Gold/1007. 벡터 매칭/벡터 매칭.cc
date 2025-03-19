#include <cfloat>
#include <cmath>
#include <iostream>
#include <limits>

#define MAX_N 20

using namespace std;

void func(pair<int, int>* dots, pair<int, int> sum, short depth,
          short num_of_minus, short n, double* result) {
  if (depth >= n) {
    if (num_of_minus != n >> 1) {
      return;
    }
    double len = sqrt(pow(sum.first, 2) + pow(sum.second, 2));
    if (*result >= len) {
      *result = len;
    }
    return;
  }

  func(
      dots,
      make_pair(sum.first + dots[depth].first, sum.second + dots[depth].second),
      depth + 1, num_of_minus, n, result);
  func(
      dots,
      make_pair(sum.first - dots[depth].first, sum.second - dots[depth].second),
      depth + 1, num_of_minus + 1, n, result);
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_exponent10);

  pair<int, int> dots[MAX_N];
  bool flags[MAX_N];

  int t;
  cin >> t;
  while (t--) {
    short n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      cin >> dots[i].first >> dots[i].second;
    }

    double result = DBL_MAX;
    func(dots, make_pair(0, 0), 0, 0, n, &result);
    cout << result << '\n';
  }

  return 0;
}