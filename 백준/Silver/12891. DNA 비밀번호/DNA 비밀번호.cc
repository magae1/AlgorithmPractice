#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  map<char, short> GEN_MAP = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

  int s, p;
  cin >> s >> p;

  string str;
  cin >> str;

  int requirements[4] = {0, 0, 0, 0};
  cin >> requirements[0] >> requirements[1] >> requirements[2] >>
      requirements[3];

  int end = 0;
  int conditions[4] = {0, 0, 0, 0};
  queue<char> password_qu;
  for (; end < p; end++) {
    char ch = str[end];
    conditions[GEN_MAP[ch]] += 1;
    password_qu.push(ch);
  }

  int ans = 0;
  do {
    bool is_ok = true;

    for (int i = 0; i < 4; i++) {
      if (requirements[i] > conditions[i]) {
        is_ok = false;
        break;
      }
    }
    if (is_ok) ans += 1;

    char front = password_qu.front();
    conditions[GEN_MAP[front]] -= 1;
    password_qu.pop();

    char ch = str[end];
    conditions[GEN_MAP[ch]] += 1;
    password_qu.push(ch);
    end++;
  } while (end <= s);

  cout << ans << '\n';
  return 0;
}