#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int>& dots, int val, bool is_left) {
  int start = 0;
  int end = dots.size() - 1;
  int mid;
  while (start <= end) {
    mid = (end + start) / 2;
    if (dots[mid] == val) {
      return mid;
    } else if (dots[mid] < val) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return is_left ? start : end;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;

  vector<int> dots(n);
  for (int i = 0; i < n; i++) {
    cin >> dots[i];
  }
  sort(dots.begin(), dots.end());

  while (m--) {
    int l, r;
    cin >> l >> r;
    int left_idx = binary_search(dots, l, true);
    int right_idx = binary_search(dots, r, false);
    int result = 0;
    if (left_idx > right_idx) {
      result = 0;
    } else {
      result = right_idx - left_idx + 1;
    }
    cout << result << '\n';
  }

  return 0;
}