#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int max_scores[3] = {
      0,
  };
  int min_scores[3] = {
      INT_MAX,
  };

  int n;
  short a, b, c;
  cin >> n;

  while (n--) {
    cin >> a >> b >> c;

    int fst_min_score = min(min_scores[0], min_scores[1]);
    int sec_min_score = min(min(min_scores[0], min_scores[1]), min_scores[2]);
    int thd_min_score = min(min_scores[1], min_scores[2]);
    min_scores[0] = fst_min_score + a;
    min_scores[1] = sec_min_score + b;
    min_scores[2] = thd_min_score + c;

    int fst_max_score = max(max_scores[0], max_scores[1]);
    int sec_max_score = max(max(max_scores[0], max_scores[1]), max_scores[2]);
    int thd_max_score = max(max_scores[1], max_scores[2]);
    max_scores[0] = fst_max_score + a;
    max_scores[1] = sec_max_score + b;
    max_scores[2] = thd_max_score + c;
  }

  pair<int, int> result{0, INT_MAX};
  for (int i = 0; i < 3; i++) {
    result.first = max(max_scores[i], result.first);
    result.second = min(min_scores[i], result.second);
  }

  cout << result.first << ' ' << result.second << '\n';
  return 0;
}