class Solution {
    private static final int MIN_NUM = -1000;
    private static final int MAX_NUM = 1000;
    private static final int MAX_LENGTH = 50;
    private static final int MAX_SUM = MAX_NUM * MAX_LENGTH;

    public int minimumPairRemoval(int[] nums) {
        int o = 0;
        for (; ; o++) {
            if (nums.length <= 1) {
                break;
            }

            boolean isNonDecreasing = true;
            for (int i = 1; i < nums.length; i++) {
                int j = i - 1;
                if (nums[j] > nums[i]) {
                    isNonDecreasing = false;
                    break;
                }
            }
            
            if (isNonDecreasing) {
                break;
            }

            int minSum = MAX_SUM + 1;
            int minIdx = -1;
            for (int i = 1; i < nums.length; i++) {
                int j = i - 1;
                int sum = nums[j] + nums[i];
                if (minSum > sum) {
                    minSum = sum;
                    minIdx = j;
                }
            }
            nums = getAddedNums(nums, minIdx);
        }
        return o;
    }

    private int[] getAddedNums(int[] nums, int leftIdx) {
        int len = nums.length - 1;
        int[] newNums = new int[len];
        newNums[leftIdx] = nums[leftIdx] + nums[leftIdx + 1];
        for (int i = 0; i < len; i++) {
            if (i < leftIdx) {
                newNums[i] = nums[i];
            } else if (i > leftIdx) {
                newNums[i] = nums[i + 1];
            }
        }
        return newNums;
    }
}
