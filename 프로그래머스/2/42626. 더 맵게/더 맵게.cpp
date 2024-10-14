#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue qu(scoville.begin(), scoville.end(), greater<int>());
    
    if (qu.top() >= K) {
        return 0;
    }
    
    int answer = 0;
    while(qu.size() >= 2) {
        int fst = qu.top();
        qu.pop();
        if (fst >= K) {
            break;
        }
        
        int sec = qu.top();
        qu.pop();
        
        qu.push(fst + sec * 2);
        answer++;
    }
    
    if (qu.top() < K) {
        return -1;
    } else {
        return answer;   
    }
}