#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

const char OPEN_BRACKET = '{';
const char CLOSE_BRACKET = '}';

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> results;

  while (true) {
    string input;
    cin >> input;
    if (input.size() > 0 && input[0] == '-') break;

    stack<char> stk;
    for (char c : input) {
      if (stk.empty()) {
        stk.push(c);
        continue;
      }
      char top = stk.top();
      if (top == OPEN_BRACKET && c == CLOSE_BRACKET) {
        stk.pop();
      } else {
        stk.push(c);
      }
    }

    int count = 0;
    bool should_open = false;
    while (!stk.empty()) {
      char cur_char = stk.top();
      stk.pop();
      if ((should_open && cur_char == CLOSE_BRACKET) ||
          (!should_open && cur_char == OPEN_BRACKET)) {
        count++;
      }
      should_open = !should_open;
    }
    results.push_back(count);
  }

  int i = 0;
  for (int r : results) {
    cout << ++i << ". " << r << '\n';
  }

  return 0;
}