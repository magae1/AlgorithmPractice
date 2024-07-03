class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) {
            return 0;
        }

        int result = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < 4; i++) {
            result = min(result, nums[i + nums.size() - 4] - nums[i]);
        }

        return result;
    }
};