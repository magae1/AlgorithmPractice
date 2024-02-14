#include <iostream>

int main() {
	size_t N;
	std::cin >> N;
	size_t i;
	size_t count = 0;
	size_t tmp_count = 9;
	for (i = 100000000; i >= 1; i /= 10) {
		if (N / i > 0) {
			count += (N - i + 1) * tmp_count;
			N = i - 1;
		}
		tmp_count--;
	}
	std::cout << count;
	return 0;
}