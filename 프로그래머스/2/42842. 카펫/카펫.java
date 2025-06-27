class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        int total = brown + yellow;
        for (int h = 3; h < total; h++) {
            if (total % h != 0) continue;
            
            int w = total / h;
            if (yellow == (w - 2)*(h - 2)) {
                answer[0] = w;
                answer[1] = h;
                break;
            }
            
        }
        return answer;
    }
}