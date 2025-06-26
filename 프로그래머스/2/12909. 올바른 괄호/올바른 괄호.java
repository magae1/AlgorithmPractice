class Solution {
    private static final char OPEN = '(';
    private static final char CLOSE = ')';
    
    boolean solution(String s) {
        int stackSize = 0;
        for (char ch : s.toCharArray()) {
            if (ch == OPEN) {
                stackSize += 1;
            } else {
                if (stackSize <= 0) {
                    return false;
                } else {
                    stackSize -= 1;
                }
            }
        }

        return stackSize > 0 ? false : true;
    }
}