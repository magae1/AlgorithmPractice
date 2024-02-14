/*
 11656 - 접미사 배열
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    string str;
    cin >> str;
    
    vector<string> tails;
    for (char ch : str) {
        tails.push_back("");
        for (auto tailIter = tails.begin(); tailIter != tails.end(); tailIter++) {
            *tailIter += ch;
        }
    }
    sort(tails.begin(), tails.end());
    
    for (string output : tails) {
        cout << output << endl;
    }
    return 0;
}
