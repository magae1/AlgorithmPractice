#include <iostream>

int stk[1000001];

int main() {
	int N;
	stk[1] = 0;
	std::cin >> N;
	for (int i = 2; i <= N; i++) {
		stk[i] = stk[i - 1] + 1;
		if (i % 2 == 0 && stk[i] > stk[i / 2] + 1)
			stk[i] = stk[i / 2] + 1;
		if (i % 3 == 0 && stk[i] > stk[i / 3] + 1)
			stk[i] = stk[i / 3] + 1;
	}
	std::cout << stk[N];
	return 0;
}