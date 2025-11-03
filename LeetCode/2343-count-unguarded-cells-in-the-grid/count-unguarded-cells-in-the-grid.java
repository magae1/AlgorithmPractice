class Solution {
    static final int EMPTY = 0;
    static final int GUARD = 1;
    static final int WALL = 2;
    static final int GUARDED = 3;

    static final int[][] DIRECTIONS = {
        {0, 1}, {0, -1}, {-1, 0}, {1, 0}
    };

    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int numOfEmptyCells = m * n;
        int[][] grid = new int[m][n];

        for (int[] w : walls) {
            grid[w[0]][w[1]] = WALL;
            numOfEmptyCells -= 1;
        }

        for (int[] g : guards) {
            grid[g[0]][g[1]] = GUARD;
            numOfEmptyCells -= 1;
        }

        for (int[] g : guards) {
            for (int[] d : DIRECTIONS) {
                int nextI = g[0] + d[0];
                int nextJ = g[1] + d[1];
                while(nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n) {
                    int c = grid[nextI][nextJ];
                    if (c == GUARD || c == WALL) {
                        break;
                    } else if (c == EMPTY) {
                        numOfEmptyCells -= 1;
                        grid[nextI][nextJ] = GUARDED;
                    }
                    nextI += d[0];
                    nextJ += d[1];
                }
            }
        }

        return numOfEmptyCells;
    }

}