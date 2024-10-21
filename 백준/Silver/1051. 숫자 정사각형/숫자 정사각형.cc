#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> nums(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    string input;
    cin >> input;
    for (int j = 0; j < m; j++) {
      nums[i][j] = input[j] - '0';
    }
  }

  int width = n > m ? m : n;
  while (width > 1) {
    for (int l = 0;; l++) {
      int r = l + width - 1;
      if (r >= m) {
        break;
      }
      for (int t = 0;; t++) {
        int d = t + width - 1;
        if (d >= n) {
          break;
        }
        if (nums[t][l] == nums[t][r] && nums[t][r] == nums[d][r] &&
            nums[d][r] == nums[d][l]) {
          cout << width * width << endl;
          return 0;
        }
      }
    }
    width--;
  }

  cout << width * width << endl;
  return 0;
}