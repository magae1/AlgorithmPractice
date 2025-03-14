#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str, explosion_str;
  cin >> str >> explosion_str;

  int explosion_size = explosion_str.length();

  stack<char> left_stk;
  stack<char> right_stk;

  for (char c : str) {
    left_stk.push(c);
  }

  while (!left_stk.empty()) {
    char left_ch = left_stk.top();
    left_stk.pop();

    if (left_ch == explosion_str[0]) {
      bool is_matched = true;
      stack<char> temp_stk;
      for (int i = 1; i < explosion_size; i++) {
        if (right_stk.empty()) {
          is_matched = false;
          break;
        }

        char cur_ch = right_stk.top();
        right_stk.pop();
        temp_stk.push(cur_ch);
        if (cur_ch != explosion_str[i]) {
          is_matched = false;
          break;
        }
      }

      if (!is_matched) {
        while (!temp_stk.empty()) {
          right_stk.push(temp_stk.top());
          temp_stk.pop();
        }
        right_stk.push(left_ch);
      }
    } else {
      right_stk.push(left_ch);
    }
  }

  if (right_stk.empty()) {
    cout << "FRULA" << '\n';
  } else {
    while (!right_stk.empty()) {
      cout << right_stk.top();
      right_stk.pop();
    }
    cout << '\n';
  }

  return 0;
}