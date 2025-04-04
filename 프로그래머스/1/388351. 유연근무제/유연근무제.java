
class Solution {
    private static final int SAT = 6;
    private static final int SUN = 7;
    private static final int INTERVAL = 10;
    
    public int solution(int[] schedules, int[][] timelogs, int startday) {
        int n = schedules.length;
        
        boolean[] checked = new boolean[n];
        for (int i = 0; i < n; i++) {
            checked[i] = true;
        }
        
        int[] times = new int[n];
        for (int i = 0; i < n; i++) {
            times[i] = (schedules[i] / 100) * 60 + schedules[i] % 100 + INTERVAL;
        }
        
        int day = startday;
        for (int d = 0; d < 7; d++) {
            if (day == SAT) {
                day += 1;
                continue;
            } else if (day == SUN) {
                day = 1;
                continue;
            }
            
            for (int e = 0; e < n; e++) {
                if (!checked[e]) continue;
                
                int log = (timelogs[e][d] / 100) * 60 + timelogs[e][d] % 100;
                if (times[e] < log) {
                    checked[e] = false;
                }
            }
            day += 1;
        }
    
        int answer = 0;
        for (int i = 0; i < n; i++) {
            if (checked[i]) {
                answer += 1;
            }
        }
        return answer;
    }
}