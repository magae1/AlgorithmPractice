#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

const short RIPED = 1;
const short UNRIPED = 0;
const short EMPTY = -1;

tuple<short, short, short> dir[6] = {{-1, 0, 0}, {1, 0, 0},  {0, -1, 0},
                                     {0, 1, 0},  {0, 0, -1}, {0, 0, 1}};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  short m, n, h;
  cin >> m >> n >> h;
  short box[100][100][100];

  queue<tuple<short, short, short>> qu;
  for (short z = 0; z < h; z++) {
    for (short y = 0; y < n; y++) {
      for (short x = 0; x < m; x++) {
        cin >> box[z][y][x];
        if (box[z][y][x] == RIPED) {
          qu.push(make_tuple(x, y, z));
        }
      }
    }
  }

  int days = 0;
  while (true) {
    int count = qu.size();
    while (count--) {
      tuple<short, short, short>& pos = qu.front();
      qu.pop();
      for (int i = 0; i < 6; i++) {
        short new_x = get<0>(pos) + get<0>(dir[i]);
        short new_y = get<1>(pos) + get<1>(dir[i]);
        short new_z = get<2>(pos) + get<2>(dir[i]);

        if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || new_z < 0 ||
            new_z >= h) {
          continue;
        }
        if (box[new_z][new_y][new_x] == UNRIPED) {
          box[new_z][new_y][new_x] = RIPED;
          qu.push(make_tuple(new_x, new_y, new_z));
        }
      }
    }

    if (qu.empty()) break;
    days += 1;
  }

  for (short z = 0; z < h; z++) {
    for (short y = 0; y < n; y++) {
      for (short x = 0; x < m; x++) {
        if (box[z][y][x] == UNRIPED) {
          cout << -1 << '\n';
          return 0;
        }
      }
    }
  }

  cout << days << '\n';
  return 0;
}