#include <iostream>

int stk[1001];

int func(int n) {
	if (n > 2) {
		if (stk[n] > 0)
			return stk[n];
		else {
			stk[n] = (func(n - 1) + func(n - 2)) % 10007;
			return stk[n];
		}
	}
	else {
		return n;
	}		
}

int main() {
	int N;
	std::cin >> N;
	std::cout << func(N);
	return 0;
}