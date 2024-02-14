#include <iostream>
#include <vector>
#include <algorithm>

struct numinfo {
	int length;
	int index;
};

void func(int n, std::vector<numinfo> v, std::vector<int> num) {
	if (n == -1)
		return;
	func(v[n].index, v, num);
	std::cout << num[n] << ' ';
}

static bool length_compare(numinfo a, numinfo b) {
	return a.length < b.length;
}

int main() {
	int N;
	std::cin >> N;	
	std::vector<int> nums(N);
	std::vector<numinfo> numsinfo(N);
	for (int i = 0; i < N; i++)
		std::cin >> nums[i];

	for (int i = 0; i < N; i++) {
		numsinfo[i].length = 1;
		numsinfo[i].index = -1;
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j] && numsinfo[i].length < numsinfo[j].length + 1) {
				numsinfo[i].length = numsinfo[j].length + 1;
				numsinfo[i].index = j;
			}
		}
	}
	auto result = std::max_element(numsinfo.begin(), numsinfo.end(), length_compare);
	int longestone = std::distance(numsinfo.begin(), result);
	std::cout << (*result).length << std::endl;
	func(longestone, numsinfo, nums);
	return 0;
}