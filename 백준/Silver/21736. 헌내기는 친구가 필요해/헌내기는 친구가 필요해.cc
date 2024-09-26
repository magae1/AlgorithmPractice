//
// Created by 정중일 on 9/26/24.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const char EMPTY = 'O';
const char WALL = 'X';
const char DOYEON = 'I';
const char PERSON = 'P';
const char VISITED = 'V';

bool is_in_boundary(int N, int M, pair<int, int>& pos) {
    if (pos.first >= 0 && pos.first < N && pos.second >= 0 && pos.second < M) {
        return true;
    }
    return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    string input;
    pair<int, int> init_pos;
    vector<vector<char>> campus(N, vector<char>(M));
    vector<pair<int,int>> moves{{-1, 0}, {1, 0}, {0, -1}, {0 , 1}};
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++){
            campus[i][j] = input[j];
            if (input[j] == DOYEON) {
                init_pos = {i, j};
            }
        }
    }

    int total = 0;
    queue<pair<int, int>> qu;
    qu.push(init_pos);
    while(!qu.empty()) {
        pair<int, int> cur_pos = qu.front();
        qu.pop();
        for (pair<int,int> m : moves) {
            pair<int, int> next_pos = {cur_pos.first + m.first, cur_pos.second + m.second};
            if (is_in_boundary(N, M, next_pos)) {
                if (campus[next_pos.first][next_pos.second] == EMPTY) {
                    qu.push(next_pos);
                    campus[next_pos.first][next_pos.second] = VISITED;
                } else if (campus[next_pos.first][next_pos.second] == PERSON) {
                    qu.push(next_pos);
                    campus[next_pos.first][next_pos.second] = VISITED;
                    total += 1;
                }
            }
        }
    }

    if (total == 0) {
        cout << "TT" << endl;
        return 0;
    }
    cout <<  total << endl;
    return 0;
}