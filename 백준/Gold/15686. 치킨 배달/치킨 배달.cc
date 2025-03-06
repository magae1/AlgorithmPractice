#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

typedef std::pair<int, int> Position;

const int HOUSE = 1;
const int CHICKEN = 2;

void func(vector<vector<short>>& dis, vector<bool>& flags, int* ans, int m,
          int c, int depth) {
  if (depth == m) {
    int temp = 0;
    for (int h = 0; h < dis[0].size(); h++) {
      int temp_min = INT_MAX;
      for (int c = 0; c < dis.size(); c++) {
        if (flags[c]) {
          temp_min = min(temp_min, (int)dis[c][h]);
        }
      }
      temp += temp_min;
    }
    *ans = min(temp, *ans);
    return;
  }

  for (; c < dis.size(); c++) {
    flags[c] = true;
    func(dis, flags, ans, m, c + 1, depth + 1);
    flags[c] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<Position> houses;
  vector<Position> chickens;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      short input;
      cin >> input;
      if (input == HOUSE) {
        houses.push_back({i, j});
      } else if (input == CHICKEN) {
        chickens.push_back({i, j});
      }
    }
  }

  int num_of_chickens = chickens.size();
  int num_of_houses = houses.size();
  vector<vector<short>> distances(num_of_chickens,
                                  vector<short>(num_of_houses, 0));
  vector<bool> flags = vector(num_of_chickens, false);
  for (int c = 0; c < num_of_chickens; c++) {
    for (int h = 0; h < num_of_houses; h++) {
      Position chicken_pos = chickens[c];
      Position house_pos = houses[h];
      distances[c][h] = abs(chicken_pos.first - house_pos.first) +
                        abs(chicken_pos.second - house_pos.second);
    }
  }
  int result = INT_MAX;
  func(distances, flags, &result, m, 0, 0);

  cout << result << '\n';
  return 0;
}