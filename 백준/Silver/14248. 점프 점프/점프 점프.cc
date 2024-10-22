#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, s;

    cin >> n;
    vector<int> rocks(n);
    vector<bool> flags(n, false);
    for (int i = 0; i < n; i++) {
        cin >> rocks[i];
    }

    cin >> s;

    int count = 0;
    // index
    queue<int> qu;
    qu.push(s - 1);
    while(!qu.empty()) {
        int idx = qu.front();
        qu.pop();
        count += 1;

        int left_idx = idx - rocks[idx];
        if (left_idx >= 0 && !flags[left_idx]) {
            qu.push(left_idx);
            flags[left_idx] = true;
        }

        int right_idx = idx + rocks[idx];
        if (right_idx < n && !flags[right_idx]) {
            qu.push(right_idx);
            flags[right_idx] = true;
        }
    }

    cout << count << endl;
    return 0;
}