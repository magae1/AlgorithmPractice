#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const char WALL = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  short n, m;
  cin >> n >> m;

  vector<pair<short, short>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  vector<vector<char>> map(n, vector<char>(m, 0));
  vector<vector<short>> distances(n, vector<short>(m, -1));
  queue<pair<short, short>> qu;
  for (short i = 0; i < n; i++) {
    for (short j = 0; j < m; j++) {
      cin >> map[i][j];
      map[i][j] -= '0';
      if (map[i][j] == 2) {
        qu.push({i, j});
        distances[i][j] = 0;
      } else if (map[i][j] == 0) {
        distances[i][j] = 0;
      }
    }
  }

  while (!qu.empty()) {
    pair<short, short>& cur = qu.front();
    qu.pop();

    for (pair<short, short>& d : dirs) {
      pair<short, short> next = {cur.first + d.first, cur.second + d.second};

      if (next.first < 0 || next.first >= n || next.second < 0 ||
          next.second >= m) {
        continue;
      }

      if (distances[next.first][next.second] >= 0) {
        continue;
      }

      if (map[next.first][next.second] == WALL) {
        distances[next.first][next.second] = 0;
        continue;
      }

      distances[next.first][next.second] = distances[cur.first][cur.second] + 1;
      qu.push(next);
    }
  }

  for (short i = 0; i < n; i++) {
    for (short j = 0; j < m; j++) {
      cout << distances[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}