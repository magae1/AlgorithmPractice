class Solution {
    public int solution(int[][] signals) {
        int len = 1;
        for (int[] signal : signals) {
            int s = signal[0] + signal[1] + signal[2];
            len = len * s;
        }
        
        int[] flags = new int[len + 1];
        for (int[] signal : signals) {
            for (int t = 1; ; ) {
                t += signal[0];
                t += signal[1];
                if (t > len) {
                    break;
                }
                for (int i = t; i > t - signal[1]; i--) {
                    flags[i] += 1;
                }
                t += signal[2];
            }
        }
        
        int answer = -1;
        for (int i = 1; i <= len; i++) {
            if (flags[i] >= signals.length) {
                return i - 1;
            }
        }
        return answer;
    }
}