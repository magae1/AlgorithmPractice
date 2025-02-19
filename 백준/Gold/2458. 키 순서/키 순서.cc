#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<vector<bool>> is_connected(n + 1, vector<bool>(n + 1, false));

  while (m--) {
    int a, b;
    cin >> a >> b;
    is_connected[a][b] = true;
  }

  for (int i = 1; i <= n; i++) {
    is_connected[i][i] = true;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (is_connected[i][k] && is_connected[k][j]) {
          is_connected[i][j] = true;
        }
      }
    }
  }

  int result = 0;
  for (int i = 1; i <= n; i++) {
    set<int> idx_set;
    for (int a = 1; a <= n; a++) {
      if (is_connected[a][i] || is_connected[i][a]) {
        idx_set.insert(a);
      }
    }

    if (idx_set.size() == n) {
      result++;
    }
  }

  cout << result << '\n';
  return 0;
}