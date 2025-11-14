class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {
        int[][] diagram = new int[n][n];

        for (int[] query : queries) {
            int x1 = query[0], x2 = query[2] + 1;
            int y1 = query[1], y2 = query[3] + 1;
            diagram[x1][y1] += 1;
            if (x2 < n && y2 < n) {
                diagram[x2][y2] += 1;
            }
            if (x2 < n) {
                diagram[x2][y1] -= 1;
            }
            if (y2 < n) {
                diagram[x1][y2] -= 1;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int above = (i == 0 ? 0 : diagram[i - 1][j]);
                int left = (j == 0 ? 0 : diagram[i][j - 1]);
                int prev = (i == 0 || j == 0 ? 0 : diagram[i - 1][j - 1]);
                diagram[i][j] += above + left - prev;
            }
        }

        return diagram;
    }
}