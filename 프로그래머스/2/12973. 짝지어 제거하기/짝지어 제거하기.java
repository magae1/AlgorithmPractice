import java.util.Stack;

class Solution
{
    public int solution(String s)
    {
        Stack<Character> stk = new Stack<>();
        char[] chArr = s.toCharArray();
        int i = 0;
        while(true) {
            while(!stk.isEmpty() && i < chArr.length) {
                Character top = stk.peek();
                if (top == chArr[i]) {
                    stk.pop();
                    i++;
                } else {
                    break;
                }
            }
            if (i >= chArr.length) break;
            stk.add(chArr[i]);
            i++;
        }
        
        if (stk.isEmpty()) {
            return 1;
        } else {
            return 0;
        }
    }
}