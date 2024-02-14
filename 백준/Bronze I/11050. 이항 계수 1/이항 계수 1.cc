#include <iostream>
using namespace std;

int main() {
    int N, K;
    int result = 1;
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        result = result * N;
        N--;
    }
    for (int i = 2; i <= K; i++)
        result = result / i;
    cout << result;
    return 0;
}
