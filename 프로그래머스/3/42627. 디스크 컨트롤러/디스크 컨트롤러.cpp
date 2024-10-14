#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> jobs) {
    auto jobSort = [](const vector<int>& l, const vector<int>& r) {
        return l[0] < r[0]; 
    };
    sort(jobs.begin(), jobs.end(), jobSort);
    
    auto priority = [](const vector<int>& l, const vector<int>& r) {
        return l[1] > r[1];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(priority)> qu {priority};
    
    int job_idx = 0;
    int processing_time = 0;
    for (int time_step = 0; ;) {
        if (qu.empty() && job_idx >= jobs.size()) break;
        
        // 단위 시간에 요청된 작업을 큐에 추가
        while(job_idx < jobs.size()) {
            vector<int>& job = jobs[job_idx];
            int start_time = job[0];
            if (start_time <= time_step) {
                qu.push(job);
                job_idx++;
            } else {
                break;
            }
        }
        
        // 대기 중인 작업이 없다면 다음 단위 시간으로
        if (qu.empty()) {
            time_step++;
            continue;
        }
        
        // 우선 대기 중인 작업 수행
        vector<int> current_job = qu.top();
        qu.pop();
        int spending_time = current_job[1];
        int waiting_time = time_step - current_job[0];
        processing_time += waiting_time + spending_time;
        time_step += spending_time;
    }
    
    return floor((float)processing_time / jobs.size());
}