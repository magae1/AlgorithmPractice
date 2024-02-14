#define MAX_PLAYERS 20
#include <iostream>
using namespace std;

short int Capability[MAX_PLAYERS][MAX_PLAYERS];
bool Teamchecker[MAX_PLAYERS];
int result = 2147483647;

void go(int index, int start, int n) {
    if (index == n/2) {
        int s_score = 0, l_score = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (Teamchecker[i]) {
                    if (Teamchecker[j])
                        s_score += Capability[i][j] + Capability[j][i];
                }
                else {
                    if (!Teamchecker[j])
                        l_score += Capability[i][j] + Capability[j][i];
                }
            }
        }
        int tmp_result = (s_score > l_score ? s_score - l_score : l_score - s_score);
        result = (result < tmp_result ? result : tmp_result);
    }
    if (result == 0)
        return;
    for (int i = start; i < n; i++) {
        if (Teamchecker[i] > 0)
            continue;
        Teamchecker[i] = true;
        go(index + 1, i + 1, n);
        Teamchecker[i] = false;
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cin >> Capability[i-1][j-1];
    }
    go(0, 0, N);
    cout << result << endl;
    return 0;
}
