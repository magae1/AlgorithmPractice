#include <iostream>
#include <stack>
#include <string>

using namespace std;

const char L = 'L';
const char D = 'D';
const char B = 'B';
const char P = 'P';

void move_left(stack<char>& front_stk, stack<char>& back_stk) {
  if (front_stk.empty()) return;
  char top = front_stk.top();
  front_stk.pop();
  back_stk.push(top);
}

void move_right(stack<char>& front_stk, stack<char>& back_stk) {
  if (back_stk.empty()) return;
  char top = back_stk.top();
  back_stk.pop();
  front_stk.push(top);
}

void delete_left(stack<char>& front_stk) {
  if (front_stk.empty()) return;
  front_stk.pop();
}

void push_left(stack<char>& front_stk, char ch) { front_stk.push(ch); }

int main() {
  string input;
  cin >> input;

  stack<char> front_stk;
  stack<char> back_stk;
  for (char c : input) {
    front_stk.push(c);
  }

  int m;
  cin >> m;
  while (m--) {
    char command;
    cin >> command;
    if (command == L) {
      move_left(front_stk, back_stk);
    } else if (command == D) {
      move_right(front_stk, back_stk);
    } else if (command == B) {
      delete_left(front_stk);
    } else if (command == P) {
      char ch;
      cin >> ch;
      push_left(front_stk, ch);
    }
  }

  while (!front_stk.empty()) {
    char front_top = front_stk.top();
    front_stk.pop();
    back_stk.push(front_top);
  }

  while (!back_stk.empty()) {
    char back_top = back_stk.top();
    cout << back_top;
    back_stk.pop();
  }
  cout << '\n';
  return 0;
}