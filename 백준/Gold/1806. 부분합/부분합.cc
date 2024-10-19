#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100001;

int main() {
  int n, s;
  cin >> n >> s;

  vector<int> sub_sums(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> sub_sums[i];
    sub_sums[i] += sub_sums[i - 1];
  }

  if (sub_sums[n] < s) {
    cout << 0 << endl;
    return 0;
  }

  int answer = MAX_N;
  int start = 0, end = 1;
  bool is_left_move = false;
  while (end <= n && answer > 1) {
    int sum = sub_sums[end] - sub_sums[start];
    if (is_left_move) {
      if (sum >= s) {
        answer = min(answer, end - start);
        is_left_move = false;
      } else {
        end++;
      }
    } else {
      if (sum >= s) {
        answer = min(answer, end - start);
        start++;
      } else {
        is_left_move = true;
      }
    }
  }

  cout << answer << endl;
  return 0;
}