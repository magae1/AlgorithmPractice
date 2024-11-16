#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  // 접시의 수, 초밥의 가짓수, 연속해서 먹는 접시의 수, 쿠폰 번호
  int n, d, k, c;
  cin >> n >> d >> k >> c;
  vector<int> sushies(n);
  for (int i = 0; i < n; i++) {
    cin >> sushies[i];
  }

  int result = 0;
  int cur_count = 0;
  map<int, int> sushi_map;
  for (int i = 0; i < k; i++) {
    int category = sushies[i];
    if (auto iter = sushi_map.find(category); iter != sushi_map.end()) {
      iter->second += 1;
    } else {
      sushi_map.insert({category, 1});
      cur_count += 1;
    }
  }
  if (auto iter = sushi_map.find(c); iter == sushi_map.end()) {
    result = cur_count + 1;
  } else {
    result = cur_count;
  }

  int left_idx = 0;
  int right_idx = k;
  while (left_idx < n) {
    int left_category = sushies[left_idx];
    int right_category = sushies[right_idx];

    auto left_iter = sushi_map.find(left_category);
    if (left_iter->second == 1) {
      sushi_map.erase(left_iter);
      cur_count--;
    } else {
      left_iter->second -= 1;
    }

    if (auto iter = sushi_map.find(right_category); iter != sushi_map.end()) {
      iter->second += 1;
    } else {
      sushi_map.insert({right_category, 1});
      cur_count++;
    }

    if (auto iter = sushi_map.find(c); iter == sushi_map.end()) {
      result = max(result, cur_count + 1);
    } else {
      result = max(result, cur_count);
    }

    left_idx++;
    right_idx++;
    right_idx = right_idx % n;
  }

  cout << result << endl;
  return 0;
}