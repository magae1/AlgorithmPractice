#include <iostream>
#include <vector>
using namespace std;

void func(vector<int>& nums, vector<int>& subSet, vector<bool>& numFlag, int curIndex) {
    if (!subSet.empty()) {
        int total = 0;
        for (auto i : subSet) {
            total += i;
        }

        numFlag[total] = true;
    }
    
    for (int i = curIndex; i < nums.size(); i++) {
        subSet.push_back(nums[i]);
        func(nums, subSet, numFlag, i+1);
        subSet.pop_back();
    }
}

int main() {
    
    int N;
    cin >> N;
    
    vector<int> nums(N);
    int highestLength = 0;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        highestLength += nums[i];
    }
    vector<bool> numFlag(highestLength+1, false);
    
    vector<int> subSet;
    func(nums, subSet, numFlag, 0);
    
    int result = highestLength+1;
    for (int i = 1; i <= highestLength; i++) {
        if (!numFlag[i]) {
            result = i;
            break;
        }
    }
    
    cout << result << endl;
    return 0;
}
