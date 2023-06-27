#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//ostream& operator<<(ostream &out, const pair<unsigned int, unsigned int> &pair) {
//    out << "(" << pair.first << " ~ " << pair.second << ")";
//    return out;
//}

int main() {
    stack<pair<unsigned int, unsigned int>> stk;
    stack<pair<unsigned int, unsigned int>> tmpStk;
    
    int N;
    cin >> N;
    
    vector<pair<unsigned int, unsigned int>> meetingRoomSchedule(N);
    for (int i = 0; i < N; i++)
        cin >> meetingRoomSchedule[i].first
        >> meetingRoomSchedule[i].second;
    
    struct {
        bool operator()(pair<unsigned int, unsigned int> fst, pair<unsigned int, unsigned int> sec) const {
            if (fst.second == sec.second)
                return fst.first < sec.first;
            return fst.second < sec.second;
        }
    } customLess;
    sort(meetingRoomSchedule.begin(), meetingRoomSchedule.end(), customLess);
    
    for (pair<unsigned int, unsigned int> schedule : meetingRoomSchedule) {
        if (stk.empty())
            stk.push(schedule);
        else {
            if (stk.top().second <= schedule.first)
                stk.push(schedule);
        }
    }
    cout << stk.size() << endl;
    
//    while(!stk.empty()) {
//        tmpStk.push(stk.top());
//        stk.pop();
//    }
//    while(!tmpStk.empty()) {
//        cout << tmpStk.top() << endl;
//        tmpStk.pop();
//    }
    return 0;
}
