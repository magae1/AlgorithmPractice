class Solution {
public:
    string reverseParentheses(string s) {
        queue<pair<int,int>> pair_stk;
        stack<int> idx_stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                idx_stk.push(i);
            } else if (s[i] == ')') {
                pair_stk.push({idx_stk.top(), i});
                idx_stk.pop();
            }
        }
        
        while(!pair_stk.empty()) {
            auto top = pair_stk.front();
            while (top.first < top.second) {
                swap(s[top.first], s[top.second]);
                top.first++;
                top.second--;
            }
            pair_stk.pop();
        }
        string result;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '(' && s[i] != ')') {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};