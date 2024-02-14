/*
 16948 - 데스 나이트
 */
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const pair<int, int> MOVEMENTS[6] = {
    {-2, -1},
    {-2, +1},
    {0, -2},
    {0, +2},
    {+2, -1},
    {+2, +1}
};

int main() {
    
    int N;
    cin >> N;
    vector<vector<short>> countBoard(N, vector<short>(N, SHRT_MAX));
    
    pair<int, int> startPoint;
    pair<int, int> endPoint;
    cin >>
    startPoint.first >> startPoint.second >>
    endPoint.first >> endPoint.second;
    
    queue<pair<int, int>> qu;
    qu.push(startPoint);
    countBoard[startPoint.first][startPoint.second] = 0;
    
    short result = -1;
    while(!qu.empty()) {
        pair<int, int> curPoint = qu.front();
        short curCount = countBoard[curPoint.first][curPoint.second];
        
        if (curPoint == endPoint) {
            result = curCount;
            break;
        }
        
        for (int i = 0; i < 6; i++) {
            pair<int, int> move = MOVEMENTS[i];
            pair<int, int> nextPoint = {
                curPoint.first + move.first,
                curPoint.second + move.second
            };
            
            if (nextPoint.first >= 0 && nextPoint.first < N &&
                nextPoint.second >= 0 && nextPoint.second < N) {
                short nextCount = countBoard[nextPoint.first][nextPoint.second];
                if (curCount + 1 < nextCount) {
                    qu.push(nextPoint);
                    countBoard[nextPoint.first][nextPoint.second] = curCount + 1;
                }
            }
        }
        qu.pop();
    }
    
    cout << result << endl;
    return 0;
}
