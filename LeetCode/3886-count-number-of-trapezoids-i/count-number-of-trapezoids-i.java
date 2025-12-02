class Solution {
    private static int DIV = 1000000007;
    public int countTrapezoids(int[][] points) {
        Map<Integer, Integer> pointCountMap = new HashMap<>();

        for (int[] point : points) {
            int x = point[0];
            int y = point[1];
            if (pointCountMap.containsKey(y)) {
                Integer count = pointCountMap.get(y);
                pointCountMap.put(y, count + 1);
            } else {
                pointCountMap.put(y, 1);
            }
        }

        int result = 0;
        long subSum = 0;
        for (int v : pointCountMap.values()) {
            long c = ((long) v * (v - 1)) / 2;
            result = (int) ((result + c * subSum) % DIV);
            subSum = (subSum + c) % DIV;
        }
        return result;
    }

    private int getCompose(int v) {
        if (v < 2) {
            return 0;
        }

        return (int)((double) v * (v - 1) % DIV / 2);
    }
}