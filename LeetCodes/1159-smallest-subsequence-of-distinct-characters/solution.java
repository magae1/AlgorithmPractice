class Solution {

    private int[] counts = new int[26];
    private boolean[] added = new boolean[26];

    public String smallestSubsequence(String s) {
        for (char ch : s.toCharArray()) {
            counts[ch - 'a'] += 1;
        }
            
        Deque<Character> deq = new ArrayDeque<>();
        for (char c : s.toCharArray()) {
            counts[c - 'a'] -= 1;
            if (isAdded(c)) {
                continue;
            }

            while (!deq.isEmpty()) {
                char top = deq.peek();
                if (c < top && counts[top - 'a'] > 0) {
                    deq.pop();
                    setUnAdded(top);
                    continue;
                }
                break;
            }

            deq.push(c);
            setAdded(c);
        }

        StringBuilder sb = new StringBuilder();
        while(!deq.isEmpty()) {
            sb.append(deq.pollLast());
        }

        return sb.toString();
    }

    private boolean isAdded(char c) {
        return added[c - 'a'];
    }

    private void setAdded(char c) {
        added[c - 'a'] = true;
    }

    private void setUnAdded(char c) {
        added[c - 'a'] = false;
    }
}
