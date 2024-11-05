#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> Position;

const char BLUE = 'B';
const char WHITE = 'W';

bool is_in_boundary(int m, int n, Position& position) {
  return position.first < m && position.first >= 0 && position.second < n &&
         position.second >= 0;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<Position> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  vector<vector<char>> battlefield(m, vector<char>(n));
  vector<vector<bool>> flags(m, vector<bool>(n, false));
  vector<Position> start_position_list;
  for (int i = 0; i < m; i++) {
    string input;
    cin >> input;
    char prev_char = ' ';
    for (int j = 0; j < n; j++) {
      battlefield[i][j] = input[j];
      if (prev_char != input[j]) {
        start_position_list.push_back({i, j});
        prev_char = input[j];
      }
    }
  }

  int blue_power = 0, white_power = 0;
  queue<Position> qu;

  for (Position& pos : start_position_list) {
    if (flags[pos.first][pos.second]) continue;
    char target_char = battlefield[pos.first][pos.second];
    int count = 1;
    qu.push(pos);
    flags[pos.first][pos.second] = true;
    while (!qu.empty()) {
      Position& cur_pos = qu.front();
      qu.pop();
      for (Position& dir : directions) {
        Position next_pos = {cur_pos.first + dir.first,
                             cur_pos.second + dir.second};

        if (!is_in_boundary(m, n, next_pos) ||
            flags[next_pos.first][next_pos.second] ||
            battlefield[next_pos.first][next_pos.second] != target_char)
          continue;

        flags[next_pos.first][next_pos.second] = true;
        count++;
        qu.push(next_pos);
      }
    }

    if (target_char == BLUE) {
      blue_power += count * count;
    } else {
      white_power += count * count;
    }
  }

  cout << white_power << " " << blue_power << endl;
  return 0;
}