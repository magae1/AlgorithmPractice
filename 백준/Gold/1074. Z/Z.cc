#include <cmath>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  pair<int, int> pos;
  cin >> n >> pos.first >> pos.second;

  int result = 0;
  while (n--) {
    int offset = pow(2, n);
    int r_idx = pos.first < offset ? 0 : 1;
    int c_idx = pos.second < offset ? 0 : 1;
    int t_idx = r_idx * 2 + c_idx;

    result += offset * offset * t_idx;
    pos.first -= offset * r_idx;
    pos.second -= offset * c_idx;
  }

  cout << result << '\n';
  return 0;
}