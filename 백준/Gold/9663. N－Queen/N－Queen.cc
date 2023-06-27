/*
 9663 - N-q
 */
#include <iostream>
#include <vector>
using namespace std;

bool flag[15][15];
bool colFlag[15];


bool isLegal(int n, int m, int N) {
    for (int i = 1; i < N; i++) {
        if (n + i < N && m + i < N) {
            if (flag[n + i][m + i])
                return false;
        }
        if (n + i < N && m - i >= 0) {
            if (flag[n + i][m - i])
                return false;
        }
        if (n - i >= 0 && m + i < N) {
            if (flag[n - i][m + i])
                return false;
        }
        if (n - i >= 0 && m - i >= 0) {
            if (flag[n - i][m - i])
                return false;
        }
    }
    
    return true;
}

void dfs(int n, int curN, int N, int* result) {
    if (curN == N) {
        *result += 1;
        return;
    }
    
    for (int j = 0; j < N; j++) {
        if (!colFlag[j]) {
            if (isLegal(n, j, N)) {
                colFlag[j] = true;
                flag[n][j] = true;
                dfs(n+1, curN+1, N, result);
                colFlag[j] = false;
                flag[n][j] = false;
            }
        }
    }
}

int main() {
    //1 <= N < 15
    int N;
    cin >> N;
    
    int result = 0;
    dfs(0, 0, N, &result);
    cout << result << endl;
    return 0;
}
