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

  int u[1000001];
  for (int i = 0; i < 1000001; i++) {
    u[i] = i;
  }

  int n, m;
  cin >> n >> m;

  char op;
  int a, b;
  while (m--) {
    cin >> op >> a >> b;

    int a_n = find_set_num(u, a);
    int b_n = find_set_num(u, b);
    if (op == '0') {
      u[a_n] = b_n;
    } else {
      cout << (a_n == b_n ? "YES" : "NO") << '\n';
    }
  }

  return 0;
}