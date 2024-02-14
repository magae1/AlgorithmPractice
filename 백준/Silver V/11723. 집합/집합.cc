#include <iostream>
#include <string>
int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int M, i;
	int S = 0;
	std::cin >> M;
	while (M--) {
		std::string str;
		std::cin >> str;
		if (str == "add") {
			std::cin >> i;
			S = S | (1 << i);
		}
		else if (str == "remove") {
			std::cin >> i;
			S = S & ~(1 << i);
		}
		else if (str == "check") {
			std::cin >> i;
			if ((S & (1 << i)) == (1 << i))
				std::cout << 1 << '\n';
			else
				std::cout << 0 << '\n';
		}
		else if (str == "toggle") {
			std::cin >> i;
			S = S ^ (1 << i);
		}
		else if (str == "all") {
			for (int j = 1; j <= 20; j++)
				S = S | (1 << j);
		}
		else if (str == "empty") {
			S = S & 0;
		}
	}
	return 0;
}