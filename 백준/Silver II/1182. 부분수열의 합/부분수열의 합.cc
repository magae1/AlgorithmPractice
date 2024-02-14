#include <iostream>
#include <vector>
using namespace std;

void func(vector<int>& nums, vector<int>& subSet, int S, int* result, int curIndex) {
    if (!subSet.empty()) {
        int total = 0;
        for (auto i : subSet) {
            total += i;
        }
        if (total == S)
            (*result)++;
    }
    
    for (int i = curIndex; i < nums.size(); i++) {
        subSet.push_back(nums[i]);
        func(nums, subSet, S, result, i+1);
        subSet.pop_back();
    }
}

int main() {
    
    int N, S;
    cin >> N >> S;
    
    vector<int> nums(N);
//    vector<bool> numFlag(N, false);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    vector<int> subSet;
    int result = 0;
    func(nums, subSet, S, &result, 0);
    
    cout << result << endl;
    return 0;
}
