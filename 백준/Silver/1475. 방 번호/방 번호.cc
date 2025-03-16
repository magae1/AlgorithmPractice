#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int result = 0;
  int set[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  string room_num;
  cin >> room_num;
  for (char c : room_num) {
    int i = c - 48;
    if (i == 6 || i == 9) {
      i = set[6] > set[9] ? 9 : 6;
    }
    set[i] += 1;
    result = max(result, set[i]);
  }

  cout << result << '\n';
  return 0;
}