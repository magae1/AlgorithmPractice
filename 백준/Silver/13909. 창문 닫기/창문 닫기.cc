#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int answer = 0;
    for (long i = 1; ; i++) {
        long square = i * i;
        if (square > n) {
            break;
        }
        answer++;
    }   

    cout << answer << endl;
    return 0;
}