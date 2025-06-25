import java.util.*;

class Solution {
    class Element {
        public final int startIdx;
        public final int endIdx;
        
        Element(int s, int e) {
            this.startIdx = s;
            this.endIdx = e;
        }
    }
    
    public int[] solution(int[] sequence, int k) {
        List<Element> list = new ArrayList<>();
        
        int s = 0, e = 0;
        int sum = 0;
        boolean isLeftMove = false;
        while (s <= e && e < sequence.length) {
            if (isLeftMove) {
                sum -= sequence[s - 1];
            } else {
                sum += sequence[e];
            }
            
            if (sum == k) {
                list.add(new Element(s, e));
                e += 1;
                isLeftMove = false;
            } else if (sum < k) {
                e += 1;
                isLeftMove = false;
            } else {
                s += 1;
                isLeftMove = true;
            }
        }
        
        int[] answer = { 0, sequence.length - 1 };
        for (Element element : list) {
            int answerLen = answer[1] - answer[0];
            int elementLen = element.endIdx - element.startIdx;
            if (elementLen < answerLen) {
                answer[0] = element.startIdx;
                answer[1] = element.endIdx;
            }
        }
        return answer;
    }
}