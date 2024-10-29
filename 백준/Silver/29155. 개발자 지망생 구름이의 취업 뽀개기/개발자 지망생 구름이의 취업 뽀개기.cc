#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_LEVEL = 5;

int main() {
  int n;
  cin >> n;

  vector<int> need_to_solved(MAX_LEVEL);
  for (int i = 0; i < MAX_LEVEL; i++) {
    cin >> need_to_solved[i];
  }

  vector<vector<int>> problems(MAX_LEVEL, vector<int>());
  for (int i = 0; i < n; i++) {
    int level, time;
    cin >> level >> time;
    problems[level - 1].push_back(time);
  }

  for (int i = 0; i < MAX_LEVEL; i++) {
    sort(problems[i].begin(), problems[i].end());
  }

  int total_time = 0;
  for (int i = 0; i < MAX_LEVEL; i++) {
    int prev_time = 0;
    for (int s = 0; s < need_to_solved[i]; s++) {
      int cur_time = problems[i][s];
      total_time += cur_time;
      if (prev_time != 0) {
        total_time += (cur_time - prev_time);
      }
      prev_time = cur_time;
    }

    if (i < MAX_LEVEL - 1) {
      total_time += 60;
    }
  }

  cout << total_time << endl;
  return 0;
}