#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100;

long func(vector<long>& results, int n) {
  if (results[n] > 0) {
    return results[n];
  }
  results[n] = func(results, n - 5) + func(results, n - 1);
  return results[n];
}

int main() {
  vector<long> results(MAX_N + 1, 0);
  results[1] = 1;
  results[2] = 1;
  results[3] = 1;
  results[4] = 2;
  results[5] = 2;
  results[6] = 3;
  results[7] = 4;
  results[8] = 5;
  results[9] = 7;
  results[10] = 9;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << func(results, n) << "\n";
  }
  return 0;
}