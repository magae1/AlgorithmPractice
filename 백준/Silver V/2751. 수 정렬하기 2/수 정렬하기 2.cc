#include <iostream>

int cmpt(const void* a, const void* b) {
	return (*(int*)a > *(int*)b ? 1 : 0);
}

int main() {
	int N;
	std::cin >> N;
	int* nums = new int[N];
	for (int i = 0; i < N; i++)
		std::cin >> nums[i];
	qsort(nums, N, sizeof(int), cmpt);
	for (int i = 0; i < N; i++)
		std::cout << nums[i] << '\n';
	return 0;
}