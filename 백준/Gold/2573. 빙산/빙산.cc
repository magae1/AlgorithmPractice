#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char ices[301][301] = {
    0,
};
char meltings[301][301] = {
    0,
};
char areas[301][301] = {
    0,
};
vector<pair<char, char>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<pair<short, short>> qu;

void calc_meltings(short n, short m) {
  for (short i = 1; i < n - 1; i++) {
    for (short j = 1; j < m - 1; j++) {
      if (ices[i][j] == 0) {
        meltings[i][j] = 0;
        continue;
      }

      char sum = 0;
      for (pair<char, char>& d : directions) {
        if (ices[i + d.first][j + d.second] == 0) {
          sum += 1;
        }
      }
      meltings[i][j] = sum;
    }
  }
}

void melt(short n, short m) {
  for (short i = 1; i < n - 1; i++) {
    for (short j = 1; j < m - 1; j++) {
      char d = ices[i][j] - meltings[i][j];
      if (d > 0) {
        ices[i][j] = d;
        qu.push({i, j});
      } else {
        ices[i][j] = 0;
      }
    }
  }
}

short find_areas(short n, short m) {
  for (short i = 1; i < n - 1; i++) {
    for (short j = 1; j < m - 1; j++) {
      areas[i][j] = 0;
    }
  }

  short count = 0;
  while (!qu.empty()) {
    pair<short, short>& cur_pos = qu.front();
    qu.pop();

    if (areas[cur_pos.first][cur_pos.second] > 0) continue;

    count += 1;
    areas[cur_pos.first][cur_pos.second] = count;
    queue<pair<short, short>> q;
    q.push(cur_pos);
    while (!q.empty()) {
      pair<short, short>& f = q.front();
      q.pop();

      for (pair<char, char>& d : directions) {
        pair<short, short> next_pos = {f.first + d.first, f.second + d.second};
        if (ices[next_pos.first][next_pos.second] == 0 ||
            areas[next_pos.first][next_pos.second] > 0) {
          continue;
        }

        areas[next_pos.first][next_pos.second] = count;
        q.push(next_pos);
      }
    }
  }
  return count;
}

bool is_remain_ices() { return !qu.empty(); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  short n, m;
  cin >> n >> m;

  for (short i = 0; i < n; i++) {
    for (short j = 0; j < m; j++) {
      short c;
      cin >> c;
      ices[i][j] = c;
      if (c > 0) {
        qu.push({i, j});
      }
    }
  }

  int years = 0;
  while (true) {
    short num_of_areas = find_areas(n, m);
    if (num_of_areas >= 2) {
      break;
    }

    calc_meltings(n, m);
    melt(n, m);
    years++;

    if (!is_remain_ices()) {
      cout << 0 << '\n';
      return 0;
    }
  }

  cout << years << '\n';
  return 0;
}