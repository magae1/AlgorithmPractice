#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  int val, prev_val = 1;
  int count = 0;
  while (n--) {
    cin >> val;

    while (val < prev_val) {
      val *= 2;
      count++;
    }
    prev_val = val;
  }

  cout << count << '\n';
  return 0;
}