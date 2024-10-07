#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int len = priorities.size();
    vector<int> priority_list(len);
    queue<int> qu;
    for (int i = 0; i < len; i++) {
        qu.push(i);
        priority_list[i] = priorities[i];
    }

    sort(priority_list.begin(), priority_list.end());
    
    int priority_idx = len - 1;
    while(!qu.empty()) {
        int highest_priority = priority_list[priority_idx];
        int cur_task_idx = qu.front();
        qu.pop();
        
        int cur_task_priority = priorities[cur_task_idx];
        if (cur_task_priority >= highest_priority) {
            answer++;
            priority_idx--;
            if (location == cur_task_idx) break;
        } else {
            qu.push(cur_task_idx);
        }
    }
    
    return answer;
}