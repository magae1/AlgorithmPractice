#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool find_num(vector<int>& nums, int target_num) {
  int start = 0, end = nums.size() - 1;

  while (start <= end) {
    int mid = (start + end) / 2;
    if (nums[mid] == target_num) {
      return true;
    } else if (nums[mid] > target_num) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;

  while (T--) {
    int n, m;
    cin >> n;
    vector<int> remem_nums(n);
    for (int i = 0; i < n; i++) {
      cin >> remem_nums[i];
    }
    sort(remem_nums.begin(), remem_nums.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
      int input;
      cin >> input;
      cout << find_num(remem_nums, input) << "\n";
    }
  }

  return 0;
}