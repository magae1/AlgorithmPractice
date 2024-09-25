#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    int min_spot_idx, cur_spot_idx;
    long cur_cost;
    cin >> N;

    vector<int> distances(N-1, 0);
    vector<int> costs(N, 0);
    for (int i = 0; i < N -1; i++) {
        cin >> distances[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> costs[i];
    }

    min_spot_idx = 0;
    cur_cost = 0;
    for (cur_spot_idx = 0; cur_spot_idx < N - 1; cur_spot_idx++) {
        if (costs[cur_spot_idx] < costs[min_spot_idx]) {
            min_spot_idx = cur_spot_idx;
        }
        cur_cost += (long)distances[cur_spot_idx] * (long)costs[min_spot_idx];
    }

    cout << cur_cost << endl;
    return 0;
}