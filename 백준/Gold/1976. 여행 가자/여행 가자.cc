#include <iostream>

using namespace std;

int find_set_num(int* s, int c) {
  if (s[c] == c) {
    return c;
  }
  return s[c] = find_set_num(s, s[c]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int cities_set[201];
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cities_set[i] = i;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char c;
      cin >> c;
      if (c == '0') continue;

      if (i == j) {
        continue;
      }

      int s_i = find_set_num(cities_set, i);
      int s_j = find_set_num(cities_set, j);
      cities_set[s_i] = s_j;
    }
  }

  int prev, cur;
  cin >> prev;
  int set_num = find_set_num(cities_set, prev);
  bool is_connected = true;
  while (--m) {
    cin >> cur;

    if (!is_connected) continue;

    if (set_num != find_set_num(cities_set, cur)) {
      is_connected = false;
    }
  }

  if (is_connected) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }

  return 0;
}