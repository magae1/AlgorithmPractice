class KthLargest {
private:
    stack<int> stk;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= k && i <= nums.size(); i++) {
            int idx = nums.size() - i;
            stk.push(nums[idx]);
        }
    }
    
    int add(int val) {
        stack<int> left_stk;
        while(true) {
            if (stk.empty() || val <= stk.top()) {
                stk.push(val);
                break;
            }
            left_stk.push(stk.top());
            stk.pop();
        }

        while(!left_stk.empty()) {
            stk.push(left_stk.top());
            left_stk.pop();
        }
        while(stk.size() > this->k) {
            stk.pop();
        }
        
        return stk.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */