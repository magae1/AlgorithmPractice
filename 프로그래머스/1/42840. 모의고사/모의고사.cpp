#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<pair<int, int>> men(3);
    men[0] = make_pair(1, 0);
    men[1] = make_pair(2, 0);
    men[2] = make_pair(3, 0);
    
    int slice_idx = 0;
    for (int i = 0; i < answers.size(); i++) {
        int ans = answers[i];
        
        if (i % 5 + 1 == ans) {
            men[0].second += 1;
        }
        
        slice_idx = i % 8;
        if ((slice_idx % 2 == 0 && ans == 2) ||
            (slice_idx == 1 && ans == 1) ||
            (slice_idx == 3 && ans == 3) ||
            (slice_idx == 5 && ans == 4) ||
            (slice_idx == 7 && ans == 5)) {
            men[1].second += 1;
        }
        
        slice_idx = i % 10;
        if ((slice_idx / 2 == 0 && ans == 3) || 
            (slice_idx / 2 == 1 && ans == 1) ||
            (slice_idx / 2 == 2 && ans == 2) ||
            (slice_idx / 2 == 3 && ans == 4) ||
            (slice_idx / 2 == 4 && ans == 5)) {
            men[2].second += 1;
        }
        
    }
    
    auto sorting = [](pair<int, int>& l, pair<int, int>& r) {
        if (l.second == r.second) {
            return l.first < r.first;
        }
        return l.second > r.second;
    };
    sort(men.begin(), men.end(), sorting);
    
    vector<int> answer;
    answer.push_back(men[0].first);
    int top_count = men[0].second;
    for (int i = 1; i < 3; i++) {
        if (men[i].second != top_count) {
            break;
        }
        answer.push_back(men[i].first);
    }
    
    return answer;
}