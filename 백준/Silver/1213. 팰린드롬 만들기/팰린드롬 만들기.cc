#include <iostream>
#include <string>

using namespace std;

#define MAX_ALPA 26

int main() {
  const string ERROR_MSG = "I'm Sorry Hansoo";
  int alpa[MAX_ALPA];
  for (int i = 0; i < MAX_ALPA; i++) {
    alpa[i] = 0;
  }

  string str;
  cin >> str;
  for (char c : str) {
    alpa[(int)c - (int)'A']++;
  }

  string result;
  bool found_odd = false;
  int odd_idx = -1;
  for (int i = 0; i < MAX_ALPA; i++) {
    int count = alpa[i];
    if (count % 2 == 1) {
      if (found_odd) {
        cout << ERROR_MSG << endl;
        return 0;
      }
      found_odd = true;
      odd_idx = i;
    }
    alpa[i] /= 2;
    count = alpa[i];
    while (count--) {
      result += (char)(i + 65);
    }
  }

  if (odd_idx >= 0) {
    result += (char)(odd_idx + 65);
  }

  for (int i = MAX_ALPA - 1; i >= 0; i--) {
    int count = alpa[i];
    while (count--) {
      result += (char)(i + 65);
    }
  }

  cout << result << endl;
  return 0;
}