#include <iostream>
int main() {
	int N;
	std::cin >> N;
	const size_t SIXSIXSIX = 666;
	size_t result = 0;
	size_t movienum = 600;
	while (N--) {
		while (movienum++) {
			size_t buf_movienum = movienum;
			bool checker_for_sixsixsix = false;
			do {
				size_t div_thousand = buf_movienum % 1000;
				if (div_thousand == SIXSIXSIX) {
					checker_for_sixsixsix = true;
					break;
				}
				if (buf_movienum < 1000)
					break;
				buf_movienum = buf_movienum / 10;
			} while (1);
			if (checker_for_sixsixsix)
				break;
		}
		result = movienum;
	}
	std::cout << result << std::endl;
	return 0;
}