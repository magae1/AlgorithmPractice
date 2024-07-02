#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int N;
    long sum = 0;
    cin >> N;

    vector<int> vec(N);
    for (auto iter = vec.begin(); iter < vec.end(); iter++) {
        cin >> *iter;
        sum += *iter;
    }
    sort(vec.begin(), vec.end());
    vector<pair<int, int>> modes;
    pair<int, int> current_mode = {vec[0], 0};
    for (auto iter = vec.begin(); iter < vec.end(); iter++) {
        if (current_mode.first == *iter) {
            current_mode.second += 1;
        } else {
            modes.push_back(current_mode);
            current_mode = make_pair(*iter, 1);
        }
    }
    modes.push_back(current_mode);

    struct {
        bool operator()(pair<int, int> a, pair<int, int> b) const {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    } modes_sort;

    sort(modes.begin(), modes.end(), modes_sort);
    pair<int, int> mode = modes.front();
    if (modes.size() > 1) {
        auto next_mode_iter = ++modes.begin();
        if (mode.second == next_mode_iter->second) {
            mode = *next_mode_iter;
        }
    }

    int average = (int) round((long double) sum / N);
    cout << average << endl;
    cout << vec[N / 2] << endl;
    cout << mode.first << endl;
    cout << vec[N - 1] - vec[0] << endl;
    return 0;
}