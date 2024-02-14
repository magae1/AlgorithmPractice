#include <iostream>
#include <vector>
#include <climits>
using namespace std;



void func(vector<int>& nums, vector<short> operandCount, vector<char>& operandIndex, int curIndex, int* high, int* low) {
    if (operandIndex.size() == nums.size()-1) {
        int tmp = nums.front();
        for (int i = 1; i < nums.size(); i++) {
            switch(operandIndex[i-1]) {
                case 0:
                    tmp += nums[i];
                    break;
                case 1:
                    tmp -= nums[i];
                    break;
                case 2:
                    tmp *= nums[i];
                    break;
                case 3:
                    tmp /= nums[i];
                    break;
            }
        }
//        cout << tmp << endl;
        *high = max(*high, tmp);
        *low = min(*low, tmp);
        return;
    }
    
    for (int i =  curIndex; i < nums.size(); i++) {
        for (int j = 0; j < 4; j++) {
            if (operandCount[j] > 0) {
                operandCount[j]--;
                operandIndex.push_back(j);
                func(nums, operandCount, operandIndex, i+1, high, low);
                operandIndex.pop_back();
                operandCount[j]++;
            }
        }
    }
}

int main() {
    
    int N;
    cin >> N;
    
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    vector<short> operandCount(4);
    for (int i = 0; i < 4; i++){
        cin >> operandCount[i];
    }
    
    vector<char> operandIndex;
    int highestResult = INT_MIN;
    int lowestResult = INT_MAX;
    
    func(nums, operandCount, operandIndex, 0, &highestResult, &lowestResult);
    cout << highestResult << endl << lowestResult << endl;
    return 0;
}
