//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

size_t GCD(size_t a, size_t b) {
	while (b != 0) {
		size_t tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int main() {
	size_t N, S;
	std::cin >> N >> S;
	size_t* nums = new size_t[N];
	for (size_t i = 0; i < N; i++) {
		size_t A;
		std::cin >> A;
		nums[i] = (S > A ? S - A : A - S);
	}
	size_t curgcd = nums[0];
	while (N > 1) {
		N--;
		curgcd = GCD(curgcd, nums[N]);
	}
	std::cout << curgcd;
	return 0;
}