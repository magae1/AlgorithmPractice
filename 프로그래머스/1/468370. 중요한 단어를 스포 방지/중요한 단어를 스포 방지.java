import java.util.*;

class Solution {
    public int solution(String message, int[][] spoiler_ranges) {
        Set<String> wordSet = new HashSet<>();
        Set<String> spoiledWordSet = new HashSet<>();
        char[] messageCharArr = message.toCharArray();
        boolean[] spoiled = new boolean[messageCharArr.length];
        
        for (int[] range: spoiler_ranges) {
            for (int s = range[0]; s <= range[1]; s++) {
                spoiled[s] = true;
            }
        }
        
        int l = 0;
        int rangeIndex = 0;
        StringBuilder st = new StringBuilder();
        for (int i = 0; i <= messageCharArr.length; i++) {
            
            if (i >= messageCharArr.length || messageCharArr[i] == ' ') {
                String word = st.toString();
                st.setLength(0);
                
                boolean isSpoiled = false;
                for (int j = l; j < i; j++) {
                    if (spoiled[j]) {
                        isSpoiled = true;
                        break;
                    }
                }
                
                if (isSpoiled) {
                    spoiledWordSet.add(word);
                } else {
                    wordSet.add(word);
                }
                l = i + 1;
                
            } else {
                st.append(messageCharArr[i]);
            }
        }

        spoiledWordSet.removeAll(wordSet);
        return spoiledWordSet.size();
    }
}