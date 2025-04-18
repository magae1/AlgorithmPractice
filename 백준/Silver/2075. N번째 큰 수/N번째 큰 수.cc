#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  short n;
  cin >> n;

  int len = n * n;
  priority_queue<long, vector<long>, greater<long>> qu;
  while (len--) {
    long l;
    cin >> l;
    qu.push(l);
    if (qu.size() > n) {
      qu.pop();
    }
  }

  cout << qu.top() << '\n';
  return 0;
}