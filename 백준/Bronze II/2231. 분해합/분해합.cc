#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int demisum(int n) {
    char chac[7];
    string str = to_string(n);
    const char* ch = str.c_str();
    strcpy(chac, ch);
    int i = 0;
    int result = 0;
    while(chac[i]) {
        result += (int)chac[i] - 48;
        i++;
    }
    return result;
}

int main(void) {
    int N, K = 1;
    int result = 0;
    cin >> N;
    while(K < N){
        if (K + demisum(K) == N) {
            result = K;
            break;
        }
        K++;
    }
    printf("%d\n",result);
    return 0;
}
