#include <algorithm>
#include <functional>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  set<string> worker_set;

  int n;
  cin >> n;
  while (n--) {
    string name, code;
    cin >> name >> code;

    if (code == "enter") {
      worker_set.insert(name);
    } else {
      worker_set.erase(name);
    }
  }

  vector<string> worker_list;
  for (auto iter = worker_set.begin(); iter != worker_set.end(); iter++) {
    worker_list.push_back(*iter);
  }

  sort(worker_list.begin(), worker_list.end(), greater<string>());
  for (auto iter = worker_list.begin(); iter != worker_list.end(); iter++) {
    cout << *iter << '\n';
  }

  return 0;
}