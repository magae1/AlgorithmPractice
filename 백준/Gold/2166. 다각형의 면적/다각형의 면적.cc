#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(1);

  pair<double, double> dots[10001];
  int n;
  cin >> n;

  pair<double, double> center = {0.0, 0.0};
  for (int i = 0; i < n; i++) {
    cin >> dots[i].first >> dots[i].second;
    center.first += dots[i].first;
    center.second += dots[i].second;
  }
  center.first /= n;
  center.second /= n;

  double v = 0.0f;
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    double sum = dots[i].first * dots[j].second +
                 dots[j].first * center.second + center.first * dots[i].second -
                 dots[j].first * dots[i].second -
                 center.first * dots[j].second - dots[i].first * center.second;
    v += sum / 2;
  }

  cout << fixed << (v < 0 ? -v : v) << '\n';
  return 0;
}