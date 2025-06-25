import java.util.*;

class Solution {
    class Element {
        public final int index;
        public final int number;
        
        Element(int index, int number) {
            this.index = index;
            this.number = number;
        }
    }
    
    public int[] solution(int[] numbers) {
        int len = numbers.length;
        int[] answer = new int[len];
        
        Stack<Element> stk = new Stack<>();
        stk.push(new Element(0, numbers[0]));
        for (int i = 1; i < len; i++) {
            while(!stk.isEmpty()) {
                Element curTop = stk.peek();
                if (curTop.number >= numbers[i]) {
                    break;
                }
                
                answer[curTop.index] = numbers[i];
                stk.pop();
            }
            
            stk.push(new Element(i, numbers[i]));
        }
        
        while(!stk.isEmpty()) {
            Element top = stk.pop();
            answer[top.index] = -1;
        }
        
        return answer;
    }
}