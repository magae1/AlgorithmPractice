#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAX_TOTAL_DISTANCE = 200000001;

void run_dijkstra(vector<vector<int>>& edges,
                  vector<vector<int>>& shortest_pathes, int n, int s, int e) {
  set<int> visited_node_set;
  visited_node_set.insert(s);

  while (true) {
    int min_distance = MAX_TOTAL_DISTANCE;
    int w = 0;
    for (int i = 1; i <= n; i++) {
      if (auto iter = visited_node_set.find(i);
          iter != visited_node_set.end()) {
        continue;
      }

      if (shortest_pathes[s][i] > min_distance) {
        continue;
      }

      min_distance = shortest_pathes[s][i];
      w = i;
    }

    if (w <= 0) {
      break;
    }

    visited_node_set.insert(w);
    for (int j = 1; j <= n; j++) {
      if (edges[w][j] > 0 && shortest_pathes[s][w] < MAX_TOTAL_DISTANCE) {
        shortest_pathes[s][j] =
            min(shortest_pathes[s][j], shortest_pathes[s][w] + edges[w][j]);
      }
    }
  }
}

int main() {
  int n, e;
  cin >> n >> e;

  vector<vector<int>> edges(n + 1, vector<int>(n + 1, 0));
  vector<vector<int>> shortest_pathes(n + 1,
                                      vector<int>(n + 1, MAX_TOTAL_DISTANCE));
  for (int i = 1; i <= n; i++) {
    shortest_pathes[i][i] = 0;
  }
  for (int i = 0; i < e; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a][b] = c;
    edges[b][a] = c;
    shortest_pathes[a][b] = c;
    shortest_pathes[b][a] = c;
  }

  int v1, v2;
  cin >> v1 >> v2;

  run_dijkstra(edges, shortest_pathes, n, 1, v1);
  if (shortest_pathes[1][v2] == MAX_TOTAL_DISTANCE) {
    run_dijkstra(edges, shortest_pathes, n, 1, v2);
  }
  run_dijkstra(edges, shortest_pathes, n, n, v1);
  if (shortest_pathes[n][v2] == MAX_TOTAL_DISTANCE) {
    run_dijkstra(edges, shortest_pathes, n, n, v2);
  }
  run_dijkstra(edges, shortest_pathes, n, v1, v2);
  if (shortest_pathes[v1][v2] == MAX_TOTAL_DISTANCE) {
    cout << -1 << endl;
    return 0;
  }

  int shortest_v1_path = shortest_pathes[1][v1] + shortest_pathes[n][v2];
  int shortest_v2_path = shortest_pathes[1][v2] + shortest_pathes[n][v1];
  if (shortest_v1_path < shortest_v2_path) {
    cout << shortest_v1_path + shortest_pathes[v1][v2] << endl;
    return 0;
  }

  if (shortest_v2_path < MAX_TOTAL_DISTANCE) {
    cout << shortest_v2_path + shortest_pathes[v1][v2] << endl;
    return 0;
  }

  cout << -1 << endl;
  return 0;
}