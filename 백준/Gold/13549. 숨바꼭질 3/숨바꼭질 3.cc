#include <iostream>
#include <queue>

#define MAX 100000
#define MIN 0

using namespace std;

struct TimeStep {
    int n;
    int second;
};

int main() {
    int N, K;
    cin >> N >> K;

    if (N >= K) {
        cout << (N - K) << endl;
        return 0;
    }

    queue<TimeStep> qu;
    int result = MAX;
    qu.push({K, 0});
    while (!qu.empty()) {
        TimeStep front = qu.front();
        qu.pop();

        if (front.second >= result) {
            break;
        }

        if (front.n % 2 == 1) {
            qu.push({front.n + 1, front.second + 1});
            qu.push({front.n - 1, front.second + 1});
            continue;
        }

        int next_n = front.n >> 1;
        if (N < next_n) {
            qu.push({next_n, front.second});
            continue;
        }

        int left = N - next_n, right = front.n - N;
        result = min(result, front.second + min(left, right));
    }

    cout << result << endl;
    return 0;
}
