class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (auto iter = logs.begin(); iter != logs.end(); iter++) {
            if (*iter == "../") {
                depth -= 1;
                depth = max(depth, 0);
            } else if (*iter != "./") {
                depth += 1;
            }
        }

        return depth;
    }
};