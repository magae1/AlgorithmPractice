class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int result = 0;
        vector<vector<bool>> flag(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1 && !flag[i][j]) {
                    if (search_island({i, j}, grid1, grid2, flag)) {
                        result += 1;
                    }
                }
            }
        }
        return result;
    }

    bool search_island(pair<int, int> position, vector<vector<int>>& grid1,
                       vector<vector<int>>& grid2, vector<vector<bool>>& flag) {
        int m = grid1.size();
        int n = grid1[0].size();
        bool result = true;
        if (grid1[position.first][position.second] == 0) {
            result = false;
        }

        vector<pair<int, int>> directions({{0, 1}, {1, 0}, {-1, 0}, {0, -1}});
        stack<pair<int, int>> stk;
        stk.push(position);
        while (!stk.empty()) {
            auto cur_pos = stk.top();
            stk.pop();

            // 플래그 변경
            flag[cur_pos.first][cur_pos.second] = true;

            // 다음 칸 탐색
            for (auto d : directions) {
                pair<int, int> next_pos = {cur_pos.first + d.first,
                                           cur_pos.second + d.second};

                if (next_pos.first >= 0 && next_pos.second >= 0 &&
                    next_pos.first < m && next_pos.second < n &&
                    grid2[next_pos.first][next_pos.second] == 1 && !flag[next_pos.first][next_pos.second]) {
                    if (grid1[next_pos.first][next_pos.second] == 0) {
                        result = false;
                    }
                    stk.push(next_pos);
                }
            }
        }
        return result;
    }
};