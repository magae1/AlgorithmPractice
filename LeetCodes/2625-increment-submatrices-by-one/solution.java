class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {
        int[][] adding = new int[n][n];

        for (int[] query : queries) {
            int u = query[1], v = query[0];
            int x = query[3], y = query[2];
            adding[v][u] += 1;

            if (x + 1 < n) {
                adding[v][x + 1] -= 1;
            }
            if (y + 1 < n) {
                adding[y + 1][u] -= 1;
            }
            if (x + 1 < n && y + 1 < n) {
                adding[y + 1][x + 1] += 1;
            }
            
        }

        int[][] diagram = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int above = (i == 0 ? 0 : diagram[i - 1][j]);
                int left = (j == 0 ? 0 : diagram[i][j - 1]);
                int prev = (i == 0 || j == 0 ? 0 : diagram[i - 1][j - 1]);
                diagram[i][j] = adding[i][j] + above + left - prev;
            }
        }

        return diagram;
    }
}
