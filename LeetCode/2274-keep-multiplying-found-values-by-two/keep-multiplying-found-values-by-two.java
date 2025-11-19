class Solution {
    private static final int MAX_VALUE = 1000;

    public int findFinalValue(int[] nums, int original) {
        boolean[] flag = new boolean[MAX_VALUE + 1];
        for (int num : nums) {
            if (num % original == 0) {
                flag[num / original] = true;
            }
        }

        int i = 1;
        int n = MAX_VALUE / original;
        for (; i <= n; ) {
            if (!flag[i]) {
                break;
            }
            i = i * 2;
        }

        return original * i;
    }
}