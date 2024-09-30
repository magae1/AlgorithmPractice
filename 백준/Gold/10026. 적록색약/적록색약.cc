#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const char RED = 'R';
const char BLUE = 'B';
const char GREEN = 'G';

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> directions{{-1,0}, {1, 0}, {0, -1}, {0, 1}};
    vector<pair<int, int>> start_points;
    vector<vector<char>> grid(N, vector<char>(N));
    vector<vector<int>> normal_flags(N, vector<int>(N, 0));
    vector<vector<int>> strange_flags(N, vector<int>(N, 0));
    pair<int, int> counts = {0, 0};
    string input;
    char prev_char = ' ';
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < N; j++) {
            grid[i][j] = input[j];
            if (input[j] != prev_char || j == 0) {
                start_points.push_back({i, j});
            }
            prev_char = input[j];
        }
    }

    queue<pair<int, int>> qu;
    for (pair<int, int> start : start_points) {
        if (normal_flags[start.first][start.second] > 0) {
            continue;
        }

        counts.first += 1;
        normal_flags[start.first][start.second] = counts.first;
        qu.push(start);
        while(!qu.empty()) {
            pair<int, int> cur_pos = qu.front();
            char cur_color = grid[cur_pos.first][cur_pos.second];
            qu.pop();
            for (pair<int, int> dir: directions) {
                pair<int, int> next_pos = {cur_pos.first + dir.first, cur_pos.second + dir.second};
                if (next_pos.first < 0 || next_pos.first >= N || next_pos.second < 0 || next_pos.second >= N) {
                    continue;
                }

                int next_flag = normal_flags[next_pos.first][next_pos.second];
                if (next_flag > 0) {
                    continue;
                }

                char next_color = grid[next_pos.first][next_pos.second];
                if (cur_color != next_color) {
                    continue;
                }
                normal_flags[next_pos.first][next_pos.second] = normal_flags[cur_pos.first][cur_pos.second];
                qu.push(next_pos);
            }
        }
    }

    for (pair<int, int> start : start_points) {
        if (strange_flags[start.first][start.second] > 0) {
            continue;
        }

        counts.second += 1;
        strange_flags[start.first][start.second] = counts.first;
        qu.push(start);
        while(!qu.empty()) {
            pair<int, int> cur_pos = qu.front();
            char cur_color = grid[cur_pos.first][cur_pos.second];
            qu.pop();
            for (pair<int, int> dir: directions) {
                pair<int, int> next_pos = {cur_pos.first + dir.first, cur_pos.second + dir.second};
                if (next_pos.first < 0 || next_pos.first >= N || next_pos.second < 0 || next_pos.second >= N) {
                    continue;
                }

                int next_flag = strange_flags[next_pos.first][next_pos.second];
                if (next_flag > 0) {
                    continue;
                }

                char next_color = grid[next_pos.first][next_pos.second];
                if (cur_color == next_color || (cur_color == RED && next_color == GREEN ) || (cur_color == GREEN && next_color == RED)) {
                    strange_flags[next_pos.first][next_pos.second] = strange_flags[cur_pos.first][cur_pos.second];
                    qu.push(next_pos);
                }
            }
        }
    }
    cout << counts.first << " " << counts.second << endl;
    return 0;
}