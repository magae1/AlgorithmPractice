/*
 1339 - 단어 수학
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int alpha[91];

int main() {
    int alphasSize = 0;
    int N;
    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < 91; i++) {
        alpha[i] = -1;
    }
    
    for (auto it = words.begin(); it != words.end(); it++) {
        cin >> *it;
        
        for (auto ch = (*it).begin(); ch != (*it).end(); ch++) {
            if (alpha[*ch] == -1) {
                alpha[*ch] = alphasSize++;
            }
        }
    }

    vector<int> num(alphasSize);
    for (int i = 1; i <= alphasSize; i++) {
        num[alphasSize - i] = 10 - i;
    }

    int result = 0;
    do {
        int tmpResult = 0;
        for (string word : words) {
            int wordSize = (int)word.size() - 1;
            int now = 1;
            for (; wordSize >= 0; wordSize--) {
                int charIndex = alpha[word[wordSize]];
                tmpResult += num[charIndex] * now;
                now *= 10;
            }
        }
        result = max(result, tmpResult);
    } while(next_permutation(num.begin(), num.end()));

    cout << result << endl;
    return 0;
}
