#include <iostream>
using namespace std;

int main() {
    int casetest;
    cin >> casetest;
    while(casetest--){
        size_t M, N;
        size_t result = 1;
        cin >> N >> M;
        for (int i = 1; i <= N; i++){
            result = (result * M) / i;
            M--;
        }
        cout << result << endl;
    }
    return 0;
}
