import java.util.Arrays;

class Solution {
    public int[] minBitwiseArray(List<Integer> nums) {
        int n = nums.size();
        int[] arr = new int[n];
        Arrays.fill(arr, -1);
        for (int i = 0; i < n; i++) {
            int num = nums.get(i);

            boolean isOnTail = true;
            int temp = num;
            int totalLen = 0;
            int tailLen = 0;
            while(temp > 0) {
                if (temp % 2 == 0) {
                    isOnTail = false;
                }

                if (isOnTail) {
                    tailLen += 1;
                }
                totalLen += 1;
                temp /= 2;
            }  

            if (tailLen == totalLen) {
                arr[i] = num >> 1;
                continue;
            }

            if (tailLen == 1) {
                arr[i] = num - 1;
            } else if (tailLen > 1) {
                int bits = 1;
                for (int j = 2; j < tailLen; j++) {
                    bits = bits << 1;
                    bits += 1;
                }
    
                arr[i] = ((num >> tailLen) << tailLen) + bits;
            }
        }
        return arr;
    }
}
