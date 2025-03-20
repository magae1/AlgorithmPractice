#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int ref_counts[10001] = { 0, };
    
    int max_ref = 0;
    for (int c : citations) {
        ref_counts[c] += 1;
        max_ref = max(c, max_ref);
    }
    
    for (int i = max_ref - 1; i >= 0; i--) {
        ref_counts[i] += ref_counts[i + 1];
    }    
    
    int answer = 0;
    for (int h = 0; h < max_ref; h++) {
        if (ref_counts[h] < h) {
            break;
        }
        answer = h;
    }
    return answer;
}