#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_HEIGHT = 100;
typedef pair<int, int> Position;

bool is_in_boundary(int n, Position& position) {
  return position.first < n && position.first >= 0 && position.second < n &&
         position.second >= 0;
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> heights(n, vector<int>(n));
  vector<vector<vector<bool>>> flags(
      n, vector<vector<bool>>(n, vector<bool>(MAX_HEIGHT + 1, false)));
  vector<pair<Position, int>> height_list(n * n);
  vector<Position> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> heights[i][j];
      height_list[i * n + j] = {{i, j}, heights[i][j]};
    }
  }

  auto sortType = [](pair<Position, int>& a, pair<Position, int>& b) {
    return a.second < b.second;
  };
  sort(height_list.begin(), height_list.end(), sortType);

  int prev_h = 0;
  vector<int> height_idxs;
  for (int i = 0; i < height_list.size(); i++) {
    int cur_h = height_list[i].second;
    if (prev_h < cur_h) {
      height_idxs.push_back(i);
      prev_h = cur_h;
    }
  }

  int max_count = 0;
  for (int cur_idx = 0; cur_idx < height_idxs.size(); cur_idx++) {
    int start_pos_idx = height_idxs[cur_idx];
    int cur_height = height_list[start_pos_idx].second - 1;

    int count = 0;
    for (int h = start_pos_idx; h < height_list.size(); h++) {
      Position pos = height_list[h].first;

      if (flags[pos.first][pos.second][cur_height]) continue;
      count++;
      queue<Position> qu;
      flags[pos.first][pos.second][cur_height] = true;
      qu.push(pos);
      while (!qu.empty()) {
        Position cur_pos = qu.front();
        qu.pop();
        for (Position d : directions) {
          Position next_pos = {cur_pos.first + d.first,
                               cur_pos.second + d.second};
          if (!is_in_boundary(n, next_pos)) continue;
          if (flags[next_pos.first][next_pos.second][cur_height] ||
              heights[next_pos.first][next_pos.second] <= cur_height)
            continue;

          flags[next_pos.first][next_pos.second][cur_height] = true;
          qu.push(next_pos);
        }
      }
    }
    max_count = max(max_count, count);
  }

  cout << max_count << endl;
  return 0;
}