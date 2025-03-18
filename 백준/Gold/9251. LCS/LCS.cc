#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  short arr[1001][1001] = {
      0,
  };

  string fst, sec;
  cin >> fst >> sec;

  for (int f = 1; f <= fst.size(); f++) {
    arr[f][1] = arr[f - 1][1];
    for (int s = 1; s <= sec.size(); s++) {
      if (fst[f - 1] == sec[s - 1]) {
        arr[f][s] = arr[f - 1][s - 1] + 1;
      } else {
        arr[f][s] = max(arr[f - 1][s], arr[f][s - 1]);
      }
    }
  }

  cout << arr[fst.size()][sec.size()] << '\n';
  return 0;
}