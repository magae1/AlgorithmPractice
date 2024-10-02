#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> sub_sums(N + 1, 0);
    for (int i = 1; i < N + 1; i++) {
        cin >> sub_sums[i];
        sub_sums[i] += sub_sums[i - 1];
    }

    pair<int, int> max_visitors = {sub_sums[0], 1};
    for (int l = 0; l < N - X + 1; l++) {
        int r = l + X;

        int num_of_visitors = sub_sums[r] - sub_sums[l];
        if (max_visitors.first < num_of_visitors) {
            max_visitors.first = num_of_visitors;
            max_visitors.second = 1;
        } else if (max_visitors.first == num_of_visitors) {
            max_visitors.second += 1;
        }
    }

    if (max_visitors.first == 0) {
        cout << "SAD" << endl;
        return 0;
    }

    cout << max_visitors.first << endl << max_visitors.second << endl;
    return 0;
}