class Solution {
    public long sumAndMultiply(int n) {
        StringBuilder sb = new StringBuilder();
        long sum = 0;
        while(n > 0) {
            int s = n % 10;
            sum += s;
            n /= 10;
            
            if (s > 0) {
                sb.append(String.valueOf(s));
            }
        }
        sb.reverse();
        String ans = sb.toString();
        long answer = 0;
        if (!ans.isBlank()) {
            answer = Long.parseLong(ans);
        }
        return answer * sum;
    }
}
