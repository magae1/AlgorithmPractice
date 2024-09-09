class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> char_set;
        int max_length = 0;
        deque<char> dq;
        for (char c : s) {
            if (auto set_iter = char_set.find(c); set_iter != char_set.end()) {
                char target_char = *(set_iter);
                max_length = max((int)dq.size(), max_length);
                while(!dq.empty()) {
                    char front = dq.front();
                    dq.pop_front();
                    char_set.erase(front);
                    if (target_char == front) {
                        break;
                    }
                }
            }
            char_set.insert(c);
            dq.push_back(c);
        }
        max_length = max((int)dq.size(), max_length);
        return max_length;
    }
};