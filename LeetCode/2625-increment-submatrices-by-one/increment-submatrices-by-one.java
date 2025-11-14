class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {
        int[][] diagram = new int[n][n];

        for (int[] query : queries) {
            for (int i = query[0]; i <= query[2]; i++) {
                for (int j = query[1]; j <= query[3]; j++) {
                    diagram[i][j] += 1;
                }
            }
        }
        return diagram;
    }
}