/*
 11399 - ATM
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    short N;
    cin >> N;
    
    vector<short> times(N);
    for (int i = 0; i < N; i++)
        cin >> times[i];
    sort(times.begin(), times.end());
    
    int result = 0;
    for (int i = 0; i < N; i++) {
        result += times[i] * (N - i);
    }
    cout << result << endl;
    return 0;
}
