#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long answer = 1;
    for (int i = 1; i <= n; i++) {
        int temp = i;
        while (temp % 10 == 0) {
            temp /= 10;
        }

        int num_of_fives = 0;
        while (temp % 5 == 0) {
            temp /= 5;
            num_of_fives++;
        }

        answer *= temp;
        answer = answer / (int)pow(2, num_of_fives);
        answer = answer % 10000000;
    }

    cout << answer % 10 << endl;
    return 0;
}