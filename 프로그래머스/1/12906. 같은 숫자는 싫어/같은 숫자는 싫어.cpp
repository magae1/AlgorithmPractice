#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    int back = -1;
    for (int a : arr) {
        if (a != back) {
            answer.push_back(a);
            back = a;
        }
    }
    return answer;
}