#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  map<pair<int, int>, int> shortcut_map;

  int n, d;
  cin >> n >> d;

  for (int i = 0; i < n; i++) {
    pair<int, int> path;
    int distance;
    cin >> path.first >> path.second >> distance;
    if (auto map_iter = shortcut_map.find(path);
        map_iter != shortcut_map.end()) {
      map_iter->second = min(map_iter->second, distance);
    } else {
      shortcut_map.insert({path, distance});
    }
  }

  vector<int> distances(d + 1);
  for (int i = 0; i <= d; i++) {
    distances[i] = i;
  }
  for (int e = 0; e <= d; e++) {
    for (int l = 0; l < e; l++) {
      pair<int, int> shortcut{l, e};
      if (auto map_iter = shortcut_map.find(shortcut);
          map_iter != shortcut_map.end()) {
        distances[e] = min(distances[e], distances[l] + map_iter->second);
      } else {
        distances[e] = min(distances[e], distances[l] + e - l);
      }
    }
  }

  cout << distances[d] << endl;
  return 0;
}