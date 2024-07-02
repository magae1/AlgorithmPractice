class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for (auto iter = arr.begin(); iter != arr.end(); iter++) {
            if (*iter % 2 == 1) {
                count += 1;
                if (count >= 3) {
                    return true;
                }
            } else {
                count = 0;
            }
        }
        return false;
    }
};