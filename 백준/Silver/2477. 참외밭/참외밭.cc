#include <iostream>
#include <stack>

using namespace std;

const int EAST = 1;
const int WEST = 2;
const int SOUTH = 3;
const int NORTH = 4;

const int NUM_OF_LINES = 6;

int main() {
  int k;
  cin >> k;

  int longer_width = 0, longer_height = 0;
  int shorter_width = 0, shorter_height = 0;
  stack<pair<int, int>> stk;
  for (int i = 0; i < NUM_OF_LINES; i++) {
    int direction, length;
    cin >> direction >> length;

    if (direction == WEST || direction == EAST) {
      longer_width = max(longer_width, length);
    } else {
      longer_height = max(longer_height, length);
    }

    if (!stk.empty()) {
      pair<int, int> top = stk.top();
      if ((top.first == EAST && direction == SOUTH) ||
          (top.first == NORTH && direction == EAST) ||
          (top.first == WEST && direction == NORTH) ||
          (top.first == SOUTH && direction == WEST)) {
        shorter_width = top.second;
        shorter_height = length;
      }
    }
    stk.push({direction, length});
  }

  if (shorter_width == 0 && shorter_height == 0) {
    pair<int, int> top = stk.top();
    shorter_width = top.second;
    while (stk.size() > 1) {
      stk.pop();
    }
    top = stk.top();
    shorter_height = top.second;
  }

  cout << (longer_width * longer_height - shorter_width * shorter_height) * k
       << endl;
  return 0;
}