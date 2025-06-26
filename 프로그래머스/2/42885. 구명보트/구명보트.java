import java.util.Arrays;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        int len = people.length;
        int l = 0, r = len - 1;
        
        Arrays.sort(people);
        
        while(l <= r) {
            int sumOfWeight = people[l] + people[r];
            
            answer += 1;
            r--;
            if (sumOfWeight <= limit) {
                l++;                
            }
        }
        
        return answer;
    }
}