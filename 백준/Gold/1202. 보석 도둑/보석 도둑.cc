#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> jewelries(n);
  multiset<int> bags;
  for (int i = 0; i < n; i++) {
    cin >> jewelries[i].first >> jewelries[i].second;
  }

  sort(jewelries.begin(), jewelries.end(),
       [](pair<int, int>& a, pair<int, int>& b) {
         if (a.second == b.second) {
           return a.first > b.first;
         }
         return a.second > b.second;
       });

  int b;
  for (int i = 0; i < k; i++) {
    cin >> b;
    bags.insert(b);
  }

  long long result = 0;
  for (int j = 0; !bags.empty() && j < n; j++) {
    pair<int, int>& jewelry = jewelries[j];

    auto iter = bags.lower_bound(jewelry.first);
    if (iter == bags.end()) {
      continue;
    }
    bags.erase(iter);
    result += jewelry.second;
  }

  cout << result << '\n';
  return 0;
}