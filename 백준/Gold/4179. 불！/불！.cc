#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const char WALL = '#';
const char JIHOON = 'J';
const char FIRE = 'F';

pair<char, char> dirs[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool is_in_boundary(pair<short, short>& pos, short r, short c) {
  if (pos.first < 0 || pos.first >= r || pos.second < 0 || pos.second >= c) {
    return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  queue<pair<pair<short, short>, int>> qu;
  queue<pair<short, short>> fire_qu;
  short r, c;
  cin >> r >> c;

  vector<vector<char>> maze(r, vector<char>(c));
  vector<vector<int>> fires(r, vector<int>(c, -1));
  for (short i = 0; i < r; i++) {
    string input;
    cin >> input;
    for (short j = 0; j < c; j++) {
      maze[i][j] = input[j];
      if (maze[i][j] == FIRE) {
        fires[i][j] = 0;
        fire_qu.push({i, j});
      } else if (maze[i][j] == JIHOON) {
        qu.push({{i, j}, 0});
      }
    }
  }

  while (!fire_qu.empty()) {
    pair<short, short>& f = fire_qu.front();
    fire_qu.pop();

    int next_t = fires[f.first][f.second] + 1;
    for (int i = 0; i < 4; i++) {
      pair<short, short> next_pos = {f.first + dirs[i].first,
                                     f.second + dirs[i].second};
      if (!is_in_boundary(next_pos, r, c) ||
          maze[next_pos.first][next_pos.second] == WALL) {
        continue;
      }

      if (fires[next_pos.first][next_pos.second] == -1 ||
          fires[next_pos.first][next_pos.second] > next_t) {
        fires[next_pos.first][next_pos.second] = next_t;
        fire_qu.push(next_pos);
      }
    }
  }

  while (!qu.empty()) {
    pair<pair<short, short>, int>& f = qu.front();
    qu.pop();

    pair<short, short>& pos = f.first;
    int next_t = f.second + 1;

    for (int i = 0; i < 4; i++) {
      pair<short, short> next_pos = {pos.first + dirs[i].first,
                                     pos.second + dirs[i].second};
      if (!is_in_boundary(next_pos, r, c)) {
        cout << next_t << '\n';
        return 0;
      }

      if (maze[next_pos.first][next_pos.second] == WALL ||
          maze[next_pos.first][next_pos.second] == JIHOON)
        continue;
      if (fires[next_pos.first][next_pos.second] >= 0 &&
          fires[next_pos.first][next_pos.second] <= next_t)
        continue;

      maze[next_pos.first][next_pos.second] = JIHOON;
      qu.push({next_pos, next_t});
    }
  }

  cout << "IMPOSSIBLE" << '\n';
  return 0;
}