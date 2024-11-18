#include <iostream>

using namespace std;

int main() {
  int n;
  int kim, lim;
  cin >> n >> kim >> lim;
  kim -= 1;
  lim -= 1;
  int round = 1;
  while (n > 0) {
    int kim_team = kim >> 1;
    int lim_team = lim >> 1;
    if (kim_team == lim_team) {
      break;
    }

    kim = (kim >> 1);
    lim = (lim >> 1);
    n /= 2;
    round++;
  }

  if (n == 0) {
    cout << -1 << endl;
  } else {
    cout << round << endl;
  }
  return 0;
}