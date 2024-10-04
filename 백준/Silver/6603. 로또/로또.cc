#include <iostream>
#include <vector>

const int MAX_COUNT = 6;
void func(std::vector<int>& nums, std::vector<int>& result, int curIndex, int curCount) {
    if (curCount >= MAX_COUNT) {
        for (auto num : result) {
            std::cout << num << ' ';
        }
        std::cout << '\n';
        return;
    }
    
    for (int i = curIndex; i < nums.size(); i++) {
            result.push_back(nums[i]);
            func(nums, result, i+1, curCount+1);
            result.pop_back();
    }
}

int main() {
    
    while(1) {
        int N;
        std::cin >> N;
        if (N == 0)
            break;
        
        std::vector<int> nums(N);
        for (int i = 0; i < N; i++) {
            std::cin >> nums[i];
        }
        
        std::vector<int> result;
        func(nums, result, 0, 0);
        
        std::cout << '\n';
    }
    return 0;
}
