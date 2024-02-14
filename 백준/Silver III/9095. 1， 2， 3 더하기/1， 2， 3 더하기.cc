#include <iostream>

int func(int n) {
	if (n > 3) {
		return func(n - 1) + func(n - 2) + func(n - 3);
	}
	else if (n == 3)
		return 4;
	else
		return n;
}

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		int N;
		std::cin >> N;
		std::cout << func(N) << std::endl;
	}
	return 0;
}