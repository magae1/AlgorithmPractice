#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool flag[8];
void func(vector<vector<int>>& dungeons, int curK, int curDungeons, int* answer) {
    *answer = max(*answer, curDungeons);
    
    for (int i = 0; i < dungeons.size(); i++) {        
        vector<int> dungenInfo = dungeons[i];
        if (!flag[i] && dungenInfo[0] <= curK) {
            flag[i]  = true;
            func(dungeons, curK - dungenInfo[1], curDungeons + 1, answer);
            flag[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    func(dungeons, k, 0, &answer);
    return answer;
}