class Solution {
    public int findGCD(int[] nums) {
        int big = Integer.MIN_VALUE;
        int small = Integer.MAX_VALUE;

        for (int n : nums) {
           big = Math.max(big, n);
           small = Math.min(small, n); 
        }

        int d = small;
        while(d >= 1) {
            if (big % d == 0 && small % d == 0) {
                return d;
            }
            d--;
        }
        return d;
    }
}
