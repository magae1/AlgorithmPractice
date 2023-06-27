#include <string>
#include <array>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
const char PERSON = 'P';
const char EMTPY_TABLE = 'O';
const char PARTITION = 'X';

bool isValidPosition(pair<int, int> position) {
    if (position.first > 4 || position.first < 0 ||
       position.second > 4 || position.second < 0)
        return false;
    return true;
}
pair<int, int> getNextPosition(pair<int, int> position, int i) {
    switch(i) {
        case 0:
            position.first--;
            break;
        case 1:
            position.second++;
            break;
        case 2:
            position.first++;
            break;
        case 3:
            position.second--;
            break;
    }
    return position;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    vector<vector<char>> waitingRoom(5, vector<char>(5));
    vector<vector<bool>> flag(5, vector<bool>(5));
    for (auto place : places) {
        vector<pair<int, int>> positions;
        //입력값(place)분석
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                char info = place[i][j];
                waitingRoom[i][j] = info;
                if (info == PERSON)
                    positions.push_back({i,j});
            }
        }
        bool isOk = true;
        for (auto personPosition : positions) {
            if (!isOk)
                break;
            for (int i = 0; i < 5; i++) {
               for (int j = 0; j < 5; j++) {
                flag[i][j] = false;
               }
            }
        
            queue<tuple<int,int, int>> qu;
            qu.push(make_tuple(personPosition.first, personPosition.second, 0));
            flag[personPosition.first][personPosition.second] = true;
            while(!qu.empty()) {
                auto curQu = qu.front();
                pair<int, int> curPosition = { get<0>(curQu), get<1>(curQu) };
                int curDistance = get<2>(curQu);
                if (curDistance == 2)
                    break;
                qu.pop();
                
                for (int i = 0; i < 4; i++) {
                    auto nextPosition = getNextPosition(curPosition, i);
                    if (isValidPosition(nextPosition) && 
                        !flag[nextPosition.first][nextPosition.second]) {
                        if (waitingRoom[nextPosition.first][nextPosition.second] == EMTPY_TABLE) {
                            flag[nextPosition.first][nextPosition.second] = true;
                            qu.push(make_tuple(nextPosition.first, nextPosition.second, curDistance + 1));
                        }
                        else if (waitingRoom[nextPosition.first][nextPosition.second] == PERSON) {
                            isOk = false;
                            break;
                        }
                    }
                }
            }            
        }
        
        if (isOk)
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    
    return answer;
}