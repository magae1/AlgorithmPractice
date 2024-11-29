#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
  int r, c;
  cin >> r >> c;

  vector<string> strs(r);
  for (int i = 0; i < r; i++) {
    cin >> strs[i];
  }

  map<int, string> sub_str_map;
  for (int j = 0; j < c; j++) {
    sub_str_map.insert({j, ""});
  }
  map<string, int> sub_str_idx_map;
  vector<bool> is_dup(c, true);

  int cur_r = r - 1;
  while (cur_r >= 0) {
    bool exist_dup = false;

    for (int j = 0; j < c; j++) {
      if (!is_dup[j]) continue;
      exist_dup = true;

      auto sub_str_iter = sub_str_map.find(j);
      sub_str_iter->second += strs[cur_r][j];
      string sub(sub_str_iter->second);
      if (auto iter = sub_str_idx_map.find(sub);
          iter != sub_str_idx_map.end()) {
        is_dup[iter->second] = true;
        is_dup[j] = true;
        iter->second = j;
      } else {
        sub_str_idx_map.insert({sub, j});
        is_dup[j] = false;
      }
    }

    if (!exist_dup) break;
    sub_str_idx_map.clear();
    cur_r--;
  }

  cout << cur_r + 1 << '\n';
  return 0;
}