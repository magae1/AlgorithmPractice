#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, x;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  cin >> x;

  sort(nums.begin(), nums.end());

  int count = 0;
  int left_idx = 0, right_idx = n - 1;
  bool is_left_move = false;
  while (left_idx < right_idx) {
    int sum = nums[left_idx] + nums[right_idx];
    if (sum == x) {
      count++;
      is_left_move = true;
    } else if (sum > x) {
      is_left_move = false;
    } else {
      is_left_move = true;
    }

    if (is_left_move) {
      left_idx++;
    } else {
      right_idx--;
    }
  }

  cout << count << endl;
  return 0;
}