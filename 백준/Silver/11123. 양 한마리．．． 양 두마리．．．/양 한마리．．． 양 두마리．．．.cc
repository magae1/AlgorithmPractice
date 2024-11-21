#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const char SHEEP = '#';

int main() {
  vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  int t;
  cin >> t;
  while (t--) {
    int h, w;
    cin >> h >> w;

    vector<pair<int, int>> start_pos;
    vector<vector<bool>> flags(h, vector<bool>(w, false));
    vector<vector<char>> grid(h, vector<char>(w, 0));
    for (int i = 0; i < h; i++) {
      string input;
      cin >> input;
      for (int j = 0; j < w; j++) {
        grid[i][j] = input[j];
        if (input[j] == SHEEP) {
          start_pos.push_back({i, j});
        }
      }
    }

    int count = 0;
    queue<pair<int, int>> qu;
    for (pair<int, int>& pos : start_pos) {
      if (flags[pos.first][pos.second]) {
        continue;
      }
      qu.push(pos);
      flags[pos.first][pos.second] = true;
      count++;
      while (!qu.empty()) {
        pair<int, int>& front = qu.front();
        qu.pop();
        for (pair<int, int>& dir : directions) {
          pair<int, int> next = {front.first + dir.first,
                                 front.second + dir.second};

          if (next.first < 0 || next.first >= h || next.second < 0 ||
              next.second >= w) {
            continue;
          }

          if (flags[next.first][next.second] ||
              grid[next.first][next.second] != SHEEP) {
            continue;
          }

          flags[next.first][next.second] = true;
          qu.push(next);
        }
      }
    }
    cout << count << endl;
  }

  return 0;
}