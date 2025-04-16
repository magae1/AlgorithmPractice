#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n;

  vector<vector<bool>> is_palindrome(n + 1, vector<bool>(n + 1, false));
  vector<int> nums(n + 1);
  for (short i = 1; i <= n; i++) {
    is_palindrome[i][i] = true;
  }

  for (short i = 1; i <= n; i++) {
    cin >> nums[i];

    short r = i;
    for (short l = r - 1; l >= 1; l--) {
      short lp = l + 1, rp = r - 1;
      bool can_be_palindrome = lp < rp ? is_palindrome[lp][rp] : true;

      if (!can_be_palindrome) continue;

      is_palindrome[l][r] = (nums[l] == nums[r]);
    }
  }

  cin >> m;
  while (m--) {
    int s, e;
    cin >> s >> e;
    cout << is_palindrome[s][e] << '\n';
  }

  return 0;
}