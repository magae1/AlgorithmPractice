class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        boolean isOne = true;
        int len = s.length();
        int[] range = { -1, -1 };
        int numOfOnes = 0;
        int currentNumOfOnes = 0;
        int[] prevZeroIndex = { -1, -1 };
        for (int i = 0; i < len; i++) {
            char ch = s.charAt(i);

            if (isOne) {
                if (ch == '0') {
                    prevZeroIndex[0] = prevZeroIndex[1];
                    prevZeroIndex[1] = i;
                    isOne = false;
                } else {
                    currentNumOfOnes++;
                }
            } else {
                if (ch == '1') {
                    int[] newRange = { prevZeroIndex[0], i - 1 };
                    int newLen = newRange[1] - newRange[0] - currentNumOfOnes;
                    int originLen = range[1] - range[0] - numOfOnes;
                    if (range[0] < 0 || originLen < newLen) {
                        range = newRange;
                        numOfOnes = currentNumOfOnes;
                    }
                    currentNumOfOnes = 1;
                    isOne = true;
                }
            }
        }

        if (!isOne) {
            int[] newRange = { prevZeroIndex[0], len - 1 };
            int newLen = newRange[1] - newRange[0] - currentNumOfOnes;
            int originLen = range[1] - range[0] - numOfOnes;
            if (range[0] < 0 || originLen < newLen) {
                range = newRange;
            }
        }

        isOne = false;
        int answer = 0;
        for (int i = 0; i < len; i++) {
            char ch = s.charAt(i);
            if (range[0] >= 0 && i >= range[0] && i <= range[1]) {
                ch = '1';
            }

            if (ch == '1') {
                answer += 1;
            }
        }
        return answer;
    }
}
