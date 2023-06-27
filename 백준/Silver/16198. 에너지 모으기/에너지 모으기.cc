/*
 16198 - 에너지 모으기
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void func(vector<short> weight, int score, int* result) {
    if (weight.size() <= 2) {
        *result = max(*result, score);
        return;
    }
    
    for (auto weightIter = weight.begin()+1; weightIter+1 != weight.end();
        weightIter++) {
        int tmpScore = (*(weightIter - 1)) * (*(weightIter + 1));
        short tmpWeight = *weightIter;
        weight.erase(weightIter);
        func(weight, score + tmpScore, result);
        weight.insert(weightIter, tmpWeight);
    }
}

int main() {
    // 3 <= N <= 10
    short N;
    cin >> N;
    
    vector<short> weight(N);
    vector<bool> flag(N);
    for (short i = 0; i < N; i++) {
        cin >> weight[i];
    }
    
    int result = 0;
    func(weight, 0, &result);
    
    cout << result << endl;
    return 0;
}
