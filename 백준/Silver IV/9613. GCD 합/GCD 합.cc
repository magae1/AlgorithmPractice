#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

unsigned long GCD(unsigned long a, unsigned long b) {
	while (b != 0) {
		unsigned long tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int main() {
	int testcase;
	scanf("%d", &testcase);
	while (testcase--) {
		int N = 0;
		scanf("%d", &N);
		unsigned long* nums = new unsigned long[N];
		for (int i = 0; i < N; i++)
			scanf("%lu", &nums[i]);
		long long sum = 0;
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++)
				sum += GCD(nums[i], nums[j]);
		}
		delete[] nums;
		printf("%lu\n", sum);
	}
	return 0;
}