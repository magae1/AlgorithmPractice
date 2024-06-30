#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> temps(N);
    vector<int> prefix_sums(N);

    cin >> temps[0];
    prefix_sums[0] = temps[0];
    for (int i = 1; i < N; i++) {
        cin >> temps[i];
        prefix_sums[i] = prefix_sums[i - 1] + temps[i];
    }

    int result = prefix_sums[K - 1];
    for (int i = 0;; i++) {
        int right_end = i + K;
        if (right_end >= N) {
            break;
        }
        result = max(result, prefix_sums[right_end] - prefix_sums[i]);
    }
    cout << result << endl;
    return 0;
}