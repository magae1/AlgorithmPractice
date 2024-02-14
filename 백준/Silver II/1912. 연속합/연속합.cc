#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> nums(n);
	std::vector<int> subsum(n);
	for (int i = 0; i < n; i++)
		std::cin >> nums[i];

	subsum[0] = nums[0];
	for (int i = 1; i < n; i++) {
		int buf_sum = subsum[i - 1] + nums[i];
		if (nums[i] > buf_sum)
			subsum[i] = nums[i];
		else
			subsum[i] = buf_sum;
	}
	auto result = std::max_element(subsum.begin(), subsum.end());
	std::cout << *result;
	return 0;
}