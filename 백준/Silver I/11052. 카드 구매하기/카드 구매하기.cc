#include <iostream>
#include <vector>

int stk[1000];

int func(std::vector<int> v, int n) {
	if (n > 1) {
		if (stk[n] == 0) {
			stk[n] = v[n - 1];
			for (int i = 1; i <= n / 2; i++)
				stk[n] = std::max(stk[n], func(v, n - i) + v[i - 1]);
		}
		return stk[n];
	}
	else {
		return v[0];
	}
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> ver(N);
	for (int i = 0; i < N; i++)
		std::cin >> ver[i];
	std::cout << func(ver, N);
	return 0;
}