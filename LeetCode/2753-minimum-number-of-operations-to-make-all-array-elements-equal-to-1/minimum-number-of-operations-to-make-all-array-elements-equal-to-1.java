class Solution {
    public int minOperations(int[] nums) {
        int numOfOnes = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                numOfOnes += 1;
            }
        }
        if (numOfOnes >= 1) {
            return nums.length - numOfOnes;
        }

        int[] gcds = new int[nums.length];
        for (int i = 0; i < nums.length - 1; i++) {
            gcds[i] = getGcd(nums[i], nums[i + 1]);
            if (gcds[i] == 1) {
                return nums.length;
            }
        }

        return func(gcds, nums.length - 2, 1);
    }

    private int func(int[] gcds, int maxIdx, int depth) {
        if (maxIdx < 1) {
            return -1;
        }
        for (int i = 0; i < maxIdx; i++) {
            gcds[i] = getGcd(gcds[i], gcds[i + 1]);
            if (gcds[i] == 1) {
                return depth + gcds.length;
            }
        }
        return func(gcds, maxIdx - 1, depth + 1);
    }

    private int getGcd(int a, int b) {
        int gcd = 1;
        int i = 2;
        while (a > 1 && b > 1) {
            if (i > a || i > b) {
                break;
            }

            if (a % i == 0 && b % i == 0) {
                a /= i;
                b /= i;
                gcd *= i;
            } else {
                i += 1;
            }
        }
        return gcd;
    }
}