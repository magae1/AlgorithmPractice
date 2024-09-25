#include <vector>
#include <set>
#include <cmath>
using namespace std;

int solution(vector<int> nums)
{   
    set<int> monster_set;
    for (int num: nums) {
        monster_set.insert(num);
    }
    return min(nums.size() / 2, monster_set.size());
}