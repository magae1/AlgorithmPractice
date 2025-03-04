#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  short t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a < b) {
      swap(a, b);
    }

    string origin = to_string((long long)a * (long long)b);
    string wrong = "";

    while (a > 0) {
      int a_remain = a % 10;
      int b_remain = max(1, b % 10);
      wrong = to_string(a_remain * b_remain) + wrong;
      a /= 10;
      b /= 10;
    }

    if (wrong != origin) {
      cout << 0 << '\n';
    } else {
      cout << 1 << '\n';
    }
  }

  return 0;
}