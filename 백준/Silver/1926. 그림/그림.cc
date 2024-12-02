#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const char PAINTED = '1';
const char EMPTY = '0';

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  vector<vector<char>> picture(n, vector<char>(m, EMPTY));
  vector<vector<bool>> flag(n, vector<bool>(m, false));
  vector<pair<int, int>> start_pos;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> picture[i][j];
      if (picture[i][j] == PAINTED) {
        start_pos.push_back({i, j});
      }
    }
  }

  int count = 0;
  int largest_picture = 0;
  queue<pair<int, int>> qu;
  for (pair<int, int>& pos : start_pos) {
    if (flag[pos.first][pos.second]) continue;

    int area = 0;
    count += 1;
    qu.push(pos);
    flag[pos.first][pos.second] = true;
    while (!qu.empty()) {
      pair<int, int>& front = qu.front();
      qu.pop();
      area += 1;
      for (pair<int, int>& dir : directions) {
        pair<int, int> next = {front.first + dir.first,
                               front.second + dir.second};
        if (next.first < 0 || next.first >= n || next.second < 0 ||
            next.second >= m) {
          continue;
        }

        if (picture[next.first][next.second] == EMPTY ||
            flag[next.first][next.second]) {
          continue;
        }

        qu.push(next);
        flag[next.first][next.second] = true;
      }
    }
    largest_picture = max(largest_picture, area);
  }

  cout << count << '\n' << largest_picture << '\n';
  return 0;
}