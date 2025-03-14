#include <iostream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str, explosion_str, answer;
  cin >> str >> explosion_str;

  int explosion_size = explosion_str.length();

  for (char c : str) {
    answer.append(1, c);
    if (answer.back() == explosion_str.back()) {
      bool is_matched = true;
      for (int i = 0; i < explosion_size - 1; i++) {
        int ans_idx = answer.length() - explosion_size + i;
        if (ans_idx < 0 || answer[ans_idx] != explosion_str[i]) {
          is_matched = false;
          break;
        }
      }
      if (is_matched) {
        answer.erase(answer.length() - explosion_size);
      }
    }
  }

  if (answer.empty()) {
    cout << "FRULA" << '\n';
  } else {
    cout << answer << '\n';
  }

  return 0;
}