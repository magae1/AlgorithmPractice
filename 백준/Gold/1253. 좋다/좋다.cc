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
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  sort(nums.begin(), nums.end());

  int result = 0;
  int idx = 0;
  while (idx < n) {
    int l = 0;
    int r = n - 1;

    while (l < r) {
      if (l == idx) {
        l++;
        continue;
      }
      if (r == idx) {
        r--;
        continue;
      }

      int sum = nums[l] + nums[r];
      if (sum == nums[idx]) {
        result += 1;
        break;
      } else if (sum < nums[idx]) {
        l++;
      } else {
        r--;
      }
    }

    idx++;
  }

  cout << result << '\n';
  return 0;
}