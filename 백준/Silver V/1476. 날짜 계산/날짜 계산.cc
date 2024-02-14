#include <iostream>

int main() {
	size_t E, S, M;
	std::cin >> E >> S >> M;
	size_t count = S;
	if (E == 15)
		E = 0;
	if (S == 28)
		S = 0;
	if (M == 19)
		M = 0;
	while (count % 15 != E || count % 28 != S || count % 19 != M) {
		count += 28;
	}
	std::cout << count;
	return 0;
}