#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<int>());

  int result = 0;
  for (int i = 0; i < n; i++) {
    result += a[i] * b[i];
  }

  cout << result << endl;

  return 0;
}