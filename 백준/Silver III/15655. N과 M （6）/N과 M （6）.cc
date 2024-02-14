#include <iostream>
#include <vector>
#include <algorithm>

void func(int index, int N, int M, std::vector<bool> checker, std::vector<int> nums, std::vector<int> printnums) {
	if (index < M) {
		for (int i = 0; i < N; i++) {
			if (checker[i] == true)
				continue;
			else {
				checker[i] = true;
				printnums[index] = nums[i];
				func(index + 1, N, M, checker, nums, printnums);
			}
		}
	}
	else {
		for (int i = 0; i < index; i++)
			printf("%d ", printnums[i]);
		printf("\n");
		return;
	}	
}


int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> nums(N);
	std::vector<int> prtnums(M);
	std::vector<bool> numChecker(N, false);
	for (int i = 0; i < N; i++)
		std::cin >> nums[i];
	std::sort(nums.begin(), nums.end());
	func(0, N, M, numChecker, nums, prtnums);
	return 0;
}