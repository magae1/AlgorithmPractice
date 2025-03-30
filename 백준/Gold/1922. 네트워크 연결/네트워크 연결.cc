#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

short find_set_num(short* u, short v) {
  if (u[v] == v) {
    return v;
  }

  return u[v] = find_set_num(u, u[v]);
}

void connect(short* u, tuple<short, short, short>& t, int l_s, int r_s,
             int* cost) {
  *cost += get<2>(t);
  u[r_s] = l_s;
}

bool is_all_connected(short* u, int n) {
  short f = u[1];
  for (int i = 2; i <= n; i++) {
    if (u[i] != f) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  short sub_sets[1001];
  vector<tuple<short, short, short> > computers(m);
  for (short i = 0; i <= n; i++) {
    sub_sets[i] = i;
  }

  short a, b, c;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    if (a != b) {
      computers[i] = make_tuple(a, b, c);
    }
  }

  if (n == 1) {
    cout << 0 << '\n';
    return 0;
  }

  sort(computers.begin(), computers.end(),
       [](tuple<short, short, short>& a, tuple<short, short, short>& b) {
         return get<2>(a) < get<2>(b);
       });

  int cost = 0;
  for (tuple<short, short, short> t : computers) {
    short left_com = find_set_num(sub_sets, get<0>(t));
    short right_com = find_set_num(sub_sets, get<1>(t));

    if (left_com == right_com) {
      continue;
    }
    connect(sub_sets, t, left_com, right_com, &cost);

    if (is_all_connected(sub_sets, n)) {
      break;
    }
  }

  cout << cost << '\n';
  return 0;
}