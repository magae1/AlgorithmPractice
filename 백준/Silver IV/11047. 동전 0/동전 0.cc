/*
 11047 - 동전 0
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> coins(N);
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end(), [](int a, int b) {
        return a > b;
    });
    
    int result = 0;
    for (int coin : coins) {
        int mux = K / coin;
        result += mux;
        K -= coin * mux;
    }
    
    cout << result << endl;
    return 0;
}
