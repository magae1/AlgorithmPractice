#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> qu;
    vector<int> answer;  
    
    for (int i = 0; i < progresses.size(); i++) {
        int remain_progress = 100 - progresses[i];
        int spend_days = ceil((float)remain_progress / speeds[i]);
        qu.push(spend_days);
    } // N
    
    while(!qu.empty()) {
        int front_days = qu.front();
        int cur_counts = 0;
        while(!qu.empty()) {
            int inner_front = qu.front();
            if (inner_front > front_days) break;
            qu.pop();
            cur_counts += 1;
        }
        answer.push_back(cur_counts);
    }

    return answer;
}