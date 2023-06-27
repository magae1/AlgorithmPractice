#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int answer = 0;
    int size = A.size();
    for (int i = 0; i < size; i++) {
        int tmp = A[i] * B[size - (i + 1)];
        answer += tmp;
    }

    return answer;
}