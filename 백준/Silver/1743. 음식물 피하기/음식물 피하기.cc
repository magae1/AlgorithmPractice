#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<bool>> trash_grid(n, vector<bool>(m, false));
  vector<vector<bool>> is_visited(n, vector<bool>(m, false));
  vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  vector<pair<int, int>> start_poses(k);
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> y >> x;
    trash_grid[y - 1][x - 1] = true;
    start_poses[i] = {y - 1, x - 1};
  }

  int biggest_count = 0;
  queue<pair<int, int>> qu;
  for (pair<int, int>& pos : start_poses) {
    if (is_visited[pos.first][pos.second]) continue;

    int count = 1;
    is_visited[pos.first][pos.second] = true;
    qu.push(pos);
    while (!qu.empty()) {
      pair<int, int>& cur = qu.front();
      qu.pop();

      for (pair<int, int>& dir : directions) {
        pair<int, int> next_pos = {cur.first + dir.first,
                                   cur.second + dir.second};
        if (next_pos.first < 0 || next_pos.first >= n || next_pos.second < 0 ||
            next_pos.second >= m) {
          continue;
        }
        if (!trash_grid[next_pos.first][next_pos.second]) {
          continue;
        }

        if (is_visited[next_pos.first][next_pos.second]) {
          continue;
        }

        is_visited[next_pos.first][next_pos.second] = true;
        qu.push(next_pos);
        count++;
      }
    }

    biggest_count = max(biggest_count, count);
  }

  cout << biggest_count << '\n';

  return 0;
}