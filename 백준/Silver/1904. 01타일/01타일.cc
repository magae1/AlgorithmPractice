#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  } else if (n == 2) {
    cout << 2 << '\n';
    return 0;
  }

  int a[3] = {1, 2, 0};
  for (int i = 0;; i++) {
    int x = i % 3;
    int y = (i + 1) % 3;
    int z = (i + 2) % 3;

    a[z] = (a[y] + a[x]) % 15746;
    if (i + 2 == n - 1) {
      cout << a[z] << '\n';
      return 0;
    }
  }
  return 0;
}