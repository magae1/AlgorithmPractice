#include <climits>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long s;
  cin >> s;

  long n;
  long sum = 0;
  for (long i = 1;; i++) {
    sum += i;

    if (sum > s) {
      n = i - 1;
      break;
    } else if (sum == s) {
      n = i;
      break;
    }
  }

  cout << n << '\n';
  return 0;
}