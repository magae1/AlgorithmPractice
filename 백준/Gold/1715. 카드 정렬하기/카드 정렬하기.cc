#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, deck;
  cin >> n;

  priority_queue<int, vector<int>, greater<int>> qu;
  for (int i = 0; i < n; i++) {
    cin >> deck;
    qu.push(deck);
  }

  int sum = 0;
  while (qu.size() > 1) {
    int a = qu.top();
    qu.pop();
    int b = qu.top();
    qu.pop();
    int temp = a + b;
    sum += temp;
    qu.push(temp);
  }

  cout << sum << '\n';
  return 0;
}