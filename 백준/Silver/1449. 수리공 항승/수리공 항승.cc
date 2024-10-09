#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;

    vector<int> leaks(N);
    for (int i = 0; i < N; i++) {
        cin >> leaks[i];
    }

    sort(leaks.begin(), leaks.end());

    int cur_pos = 0;
    int num_of_tapes = 0;
    for (int leak : leaks) {
        if (cur_pos <= leak) {
            cur_pos = leak + L;
            num_of_tapes += 1;
        }
    }

    cout << num_of_tapes << endl;
    return 0;
}