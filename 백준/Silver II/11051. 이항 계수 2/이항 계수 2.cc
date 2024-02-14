#include <iostream>
using namespace std;

size_t gcd(size_t frt, size_t sec){
    while (sec != 0){
        size_t temp = frt % sec;
        frt = sec;
        sec = temp;
    }
    return frt;
}

int main() {
    size_t N, K;
    const size_t C = 10007;
    size_t result = 1;
    cin >> N >> K;
    size_t * div = new size_t[K + 1];
    for (size_t i = 1; i <= K; i++)
        div[i] = i;
    for (int j = 1; j <= K; j++) {
        size_t mult = N;
        size_t div_pos = K;
        while (mult > 1 && div_pos > 1){
            if (div[div_pos] > 1){
                size_t thegcd = gcd(mult, div[div_pos]);
                if (thegcd > 1) {
                    mult = mult / thegcd;
                    div[div_pos] = div[div_pos] / thegcd;
                }
            }
            div_pos--;
        }
        result = (result * (mult % C)) % C;
        N--;
    }
    cout << result << endl;
    return 0;
}
