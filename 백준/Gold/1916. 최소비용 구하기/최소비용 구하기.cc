#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAX_COST = 100000000;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> city_costs =
      vector<vector<int>>(n + 1, vector<int>(n + 1, MAX_COST));

  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    city_costs[a][b] = min(city_costs[a][b], c);
  }

  for (int i = 1; i <= n; i++) {
    city_costs[i][i] = 0;
  }

  int s, d;
  cin >> s >> d;

  set<int> visited_cities = {s};
  do {
    int cur_city = 0;
    int min_cost = MAX_COST + 1;
    for (int i = 1; i <= n; i++) {
      if (auto iter = visited_cities.find(i); iter != visited_cities.end()) {
        continue;
      }

      if (city_costs[s][i] < min_cost) {
        cur_city = i;
        min_cost = city_costs[s][i];
      }
    }

    visited_cities.insert(cur_city);

    for (int i = 1; i <= n; i++) {
      city_costs[s][i] = min(city_costs[s][i],
                             city_costs[s][cur_city] + city_costs[cur_city][i]);
    }

  } while (visited_cities.size() < n);

  cout << city_costs[s][d] << endl;

  return 0;
}