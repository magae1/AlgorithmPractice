#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string a, b;
  cin >> a >> b;

  short a_off = a.size() - 1;
  short b_off = b.size() - 1;
  char ch = 0;
  stack<char> stk;
  while (true) {
    if (a_off >= 0) {
      ch += a[a_off] - '0';
      a_off--;
    }
    if (b_off >= 0) {
      ch += b[b_off] - '0';
      b_off--;
    }

    if (a_off < 0 && b_off < 0 && ch == 0) break;

    stk.push(ch % 10 + '0');
    ch /= 10;
  }

  while (!stk.empty()) {
    cout << stk.top();
    stk.pop();
  }
  cout << '\n';
  return 0;
}