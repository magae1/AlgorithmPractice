class Solution {
    private static final char BLANK = ' ';
    
    public String solution(String s) {
        StringBuilder sb = new StringBuilder();
        boolean isFirstLetter = true;
        for (char ch : s.toCharArray()) {
            if (ch == BLANK) {
                isFirstLetter = true;
                sb.append(ch);
                continue;
            }
            
            if (isFirstLetter) {
                if (ch >= 97) {
                    ch = (char)(ch - 32);
                }
                
                sb.append(ch);
                isFirstLetter = false;
            } else {
                if (ch < 97) {
                    ch = (char)(ch + 32);
                }
                
                sb.append(ch);
            }
        }

        return sb.toString();
    }
}