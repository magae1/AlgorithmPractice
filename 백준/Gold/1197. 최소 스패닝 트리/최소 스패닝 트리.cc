#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int find_set_num(int* u, int v) {
  if (u[v] == v) {
    return v;
  }
  return u[v] = find_set_num(u, u[v]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int u[10001];
  for (int i = 0; i < 10001; i++) {
    u[i] = i;
  }

  int v, e;
  cin >> v >> e;

  vector<tuple<int, int, int>> edge_weights(e);
  for (int i = 0; i < e; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edge_weights[i] = make_tuple(a, b, c);
  }

  sort(edge_weights.begin(), edge_weights.end(),
       [](tuple<int, int, int>& a, tuple<int, int, int>& b) {
         return get<2>(a) < get<2>(b);
       });

  int total_w = 0;
  int count = 0;
  for (tuple<int, int, int>& t : edge_weights) {
    int a = get<0>(t);
    int b = get<1>(t);
    int w = get<2>(t);

    int a_n = find_set_num(u, a);
    int b_n = find_set_num(u, b);
    if (a_n == b_n) {
      continue;
    }

    u[a_n] = b_n;
    total_w += w;
    count++;

    if (count == v - 1) break;
  }

  cout << total_w << '\n';
  return 0;
}