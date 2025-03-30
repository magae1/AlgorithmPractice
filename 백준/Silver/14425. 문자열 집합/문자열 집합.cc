#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  set<string> str_set;
  int n, m;
  cin >> n >> m;

  while (n--) {
    string input;
    cin >> input;

    str_set.insert(input);
  }

  int count = 0;
  while (m--) {
    string input;
    cin >> input;

    if (auto iter = str_set.find(input); iter != str_set.end()) {
      count += 1;
    }
  }

  cout << count << '\n';
  return 0;
}