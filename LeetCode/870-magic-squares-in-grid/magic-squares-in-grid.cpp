class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if (row < 3 || col < 3) {
            return 0;
        }

        int result = 0;
        for (int i = row - 3; i >= 0; i--) {
            for (int j = col - 3; j >= 0; j--) {
                if (checkMagicSquare(i, j, grid)) {
                    result += 1;
                }
            }
        }
        return result;
    }

private:
    bool checkMagicSquare(int row_offset, int col_offset,
                          vector<vector<int>>& grid) {
        set<int> e{1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int target = grid[row_offset + i][col_offset + j];
                if (auto e_iter = e.find(target); e_iter != e.end()) {
                    e.erase(e_iter);
                } else {
                    return false;
                }
            }
        }

        if (e.size() > 0) {
            return false;
        }

        int sum = grid[row_offset][col_offset + 2] +
                  grid[row_offset + 1][col_offset + 1] +
                  grid[row_offset + 2][col_offset];

        for (int i = 0; i < 3; i++) {
            int temp_col = 0;
            int temp_row = 0;
            for (int j = 0; j < 3; j++) {
                temp_col += grid[row_offset + i][col_offset + j];
                temp_row += grid[row_offset + j][col_offset + i];
            }
            if (sum != temp_col || sum != temp_row) {
                return false;
            }
        }

        if (sum != grid[row_offset][col_offset] +
                       grid[row_offset + 1][col_offset + 1] +
                       grid[row_offset + 2][col_offset + 2]) {
            return false;
        }

        return true;
    }
};