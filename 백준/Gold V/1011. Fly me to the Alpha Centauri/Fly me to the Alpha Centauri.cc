#include <iostream>

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		size_t x, y;
		size_t result;
		std::cin >> x >> y;
		size_t distance_x_to_y = y - x;
		size_t squarenum = 1;
		if (distance_x_to_y > 1) {
			while (squarenum * squarenum < distance_x_to_y)
				squarenum++;
			if (distance_x_to_y >= (squarenum * squarenum + (squarenum - 1) * (squarenum - 1) + 1) >> 1)
				result = squarenum + squarenum - 1;
			else
				result = squarenum + squarenum - 2;
		}
		else {
			result = 1;
		}
		std::cout << result << std::endl;
	}
	return 0;
}