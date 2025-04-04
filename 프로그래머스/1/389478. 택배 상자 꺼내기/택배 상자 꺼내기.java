class Solution {
    public int solution(int n, int w, int num) {
        n -= 1;
        num -= 1;
        
        int t = w * 2;
        int answer = (n / t - num / t) * 2;
        
        n = n % t;
        num = num % t;
        int i_n = n < w ? 0 : 1;
        int j_n = n < w ? n : t - n - 1;
        
        int i_num = num < w ? 0 : 1;
        int j_num = num < w ? num : t - num - 1;
        
        answer += (i_n - i_num);
        if (i_n == 0) {
            if (j_num <= j_n) {
                answer += 1;
            }
        } else {
            if (j_n <= j_num) {
                answer += 1;
            }
        }
        
        return answer;
    }
}