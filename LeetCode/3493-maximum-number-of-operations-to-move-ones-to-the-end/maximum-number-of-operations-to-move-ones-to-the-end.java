class Solution {
    public int maxOperations(String s) {
        if (s.length() <= 1) {
            return 0;
        }

        int result = 0;
        int subSum = 0;
        int l = 0;
        int r = s.length() - 1;
        for (; l < s.length(); l++) {
            if (s.charAt(l) == '1') {
                break;
            }
        }
        for (int i = l; i <= r; i++) {
            if (s.charAt(i) == '1') {
                subSum += 1;
            }
        }

        while(l < r) {
            int minus = 0;
            if (s.charAt(r) == '1') {
                minus += 1;
            }
            r -= 1;

            for (; r >= 0; r--) {
                if (s.charAt(r) == '1') {
                    if (s.charAt(r + 1) == '0') {
                        break;
                    } else {
                        minus += 1;
                    }
                }
            }

            subSum -= minus;
            result += subSum;
        }

        return result;
    }
}