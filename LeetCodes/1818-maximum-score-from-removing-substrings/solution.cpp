class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;
        stack<char> left_stk;
        stack<char> right_stk;

        for (int i = 0; i < s.size(); i++) {
            left_stk.push(s[i]);
        }

        while (true) {
            int added_score = 0;

            while (!left_stk.empty()) {
                if (right_stk.empty()) {
                    right_stk.push(left_stk.top());
                    left_stk.pop();
                    continue;
                }

                char left_top = left_stk.top();
                char right_top = right_stk.top();

                if (left_top == 'a' && right_top == 'b' && x > y) {
                    left_stk.pop();
                    right_stk.pop();
                    added_score += x;
                    continue;
                }

                if (left_top == 'b' && right_top == 'a' && x < y) {
                    left_stk.pop();
                    right_stk.pop();
                    added_score += y;
                    continue;
                }

                right_stk.push(left_stk.top());
                left_stk.pop();
            }

            while (!right_stk.empty()) {
                if (left_stk.empty()) {
                    left_stk.push(right_stk.top());
                    right_stk.pop();
                    continue;
                }

                char left_top = left_stk.top();
                char right_top = right_stk.top();

                if (left_top == 'a' && right_top == 'b') {
                    left_stk.pop();
                    right_stk.pop();
                    added_score += x;
                    continue;
                }

                if (left_top == 'b' && right_top == 'a') {
                    left_stk.pop();
                    right_stk.pop();
                    added_score += y;
                    continue;
                }

                left_stk.push(right_stk.top());
                right_stk.pop();
                continue;
            }
            if (added_score == 0) {
                break;
            }
            score += added_score;
        }

        return score;
    }
};
