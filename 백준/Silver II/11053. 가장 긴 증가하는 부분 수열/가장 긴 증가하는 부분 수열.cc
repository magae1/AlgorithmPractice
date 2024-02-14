#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N;
	std::cin >> N;	
	std::vector<int> nums(N);
	std::vector<int> numsinfo(N);
	for (int i = 0; i < N; i++) {
		std::cin >> nums[i];
		numsinfo[i] = 1;
	}		

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[j] < nums[i] && numsinfo[j] + 1 > numsinfo[i])
				numsinfo[i] = numsinfo[j] + 1;
		}
	}
	auto result = std::max_element(numsinfo.begin(), numsinfo.end());
	std::cout << *result;
	return 0;
}