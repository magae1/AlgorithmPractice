#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

typedef pair<int, int> Position;

const char WALL = '1';
const char EMPTY = '0';

bool is_in_boundary(int n, int m, Position& pos) {
  return pos.first >= 0 && pos.first < n && pos.second >= 0 && pos.second < m;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> directions{make_pair(1, 0), make_pair(0, 1),
                                    make_pair(-1, 0), make_pair(0, -1)};
  vector<vector<char>> maze(n, vector<char>(m, 0));
  vector<vector<vector<bool>>> is_visited(
      2, vector<vector<bool>>(n, vector<bool>(m, false)));
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < m; j++) {
      maze[i][j] = str[j];
    }
  }

  if (n == 1 && m == 1) {
    cout << 1 << endl;
    return 0;
  }

  int answer = 1000001;
  queue<tuple<Position, int, int>> qu;
  Position start_pos = {0, 0};
  is_visited[0][start_pos.first][start_pos.second] = true;
  is_visited[1][start_pos.first][start_pos.second] = true;
  qu.push(make_tuple(start_pos, 1, 0));
  while (!qu.empty()) {
    Position cur_pos = get<0>(qu.front());
    int count = get<1>(qu.front());
    int depth = get<2>(qu.front());
    qu.pop();

    if (cur_pos.first == n - 1 && cur_pos.second == m - 1) {
      answer = min(answer, count);
      break;
    }

    for (int i = 0; i < 4; i++) {
      pair<int, int>& dir = directions[i];
      Position next_pos = {cur_pos.first + dir.first,
                           cur_pos.second + dir.second};

      if (!is_in_boundary(n, m, next_pos) ||
          is_visited[depth][next_pos.first][next_pos.second])
        continue;

      if (maze[next_pos.first][next_pos.second] == WALL) {
        if (depth == 0) {
          qu.push(make_tuple(next_pos, count + 1, 1));
          is_visited[1][next_pos.first][next_pos.second] = true;
          is_visited[0][next_pos.first][next_pos.second] = true;
        }
      } else {
        qu.push(make_tuple(next_pos, count + 1, depth));
        is_visited[depth][next_pos.first][next_pos.second] = true;
      }
    }
  }

  cout << (answer == 1000001 ? -1 : answer) << endl;
  return 0;
}