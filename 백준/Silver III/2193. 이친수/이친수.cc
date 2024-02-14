#include <iostream>

size_t buf0[91];
size_t buf1[91];

int main() {
	buf1[1] = 1;
	size_t N;
	std::cin >> N;
	for (size_t i = 2; i <= N; i++) {
		buf0[i] = buf1[i - 1] + buf0[i - 1];
		buf1[i] = buf0[i - 1];
	}
	std::cout << buf0[N] + buf1[N];
	return 0;
}