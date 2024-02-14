#include <iostream>

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		int M, N, x, y;
		int result = -1;
		std::cin >> M >> N >> x >> y;
		int tmp = x;
		while (tmp <= M * N) {
			tmp -= 1;
			if ((tmp % N) + 1 == y) {
				result = tmp + 1;
				break;
			}
			tmp += M;
			tmp += 1;
		}
		std::cout << result << std::endl;
	}
	return 0;
}