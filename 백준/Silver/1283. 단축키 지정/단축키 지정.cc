#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string n_str;
  int n;
  getline(cin, n_str, '\n');
  n = stoi(n_str);

  set<char> shortcuts;
  vector<string> results(n);
  for (int i = 0; i < n; i++) {
    string str;
    getline(cin, str, '\n');

    vector<string> words;
    stringstream ss(str);
    string word;
    while (ss >> word) {
      words.push_back(word);
    }

    bool is_added = false;
    for (string& w : words) {
      char first_char = w[0];
      if (first_char >= 'a') {
        first_char -= 32;
      }
      if (auto iter = shortcuts.find(first_char); iter == shortcuts.end()) {
        shortcuts.insert(first_char);
        is_added = true;
        w.insert(0, 1, '[');
        w.insert(2, 1, ']');
        break;
      }
    }

    if (is_added) {
      string s = words[0];
      for (int i = 1; i < words.size(); i++) {
        s += ' ' + words[i];
      }
      results[i] = s;
      continue;
    }

    for (string& w : words) {
      int size = w.size();
      for (int i = 1; i < size; i++) {
        char c = w[i];
        if (c >= 'a') {
          c -= 32;
        }
        if (auto iter = shortcuts.find(c); iter == shortcuts.end()) {
          shortcuts.insert(c);
          is_added = true;
          w.insert(i, 1, '[');
          w.insert(i + 2, 1, ']');
          break;
        }
      }
      if (is_added) break;
    }

    string s = words[0];
    for (int i = 1; i < words.size(); i++) {
      s += ' ' + words[i];
    }
    results[i] = s;
  }

  for (string r : results) {
    cout << r << endl;
  }
  return 0;
}