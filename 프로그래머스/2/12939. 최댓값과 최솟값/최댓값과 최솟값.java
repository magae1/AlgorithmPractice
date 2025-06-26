import java.util.*;

class Solution {
    public String solution(String s) {
        long max = Long.MIN_VALUE, min = Long.MAX_VALUE;
        StringTokenizer st = new StringTokenizer(s, " ");
        
        while(st.hasMoreTokens()) {
            long value = Long.parseLong(st.nextToken());
            max = Math.max(max, value);
            min = Math.min(min, value);
        }
        
        return min + " " + max;
    }
}