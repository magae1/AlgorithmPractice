#include <iostream>

long long p1[100001];
long long p2[100001];
long long p3[100001];

int main() {
	p1[1] = 1, p1[3] = 1;
	p2[2] = 1, p2[3] = 1;
	p3[3] = 1;
	int T;
	std::cin >> T;
	while (T--) {
		long long N;
		std::cin >> N;
		for (long long i = 4; i <= N; i++) {
			p3[i] = (p1[i - 3] + p2[i - 3]) % 1000000009;
			p2[i] = (p1[i - 2] + p3[i - 2]) % 1000000009;
			p1[i] = (p2[i - 1] + p3[i - 1]) % 1000000009;
		}
		std::cout << (((p1[N] + p2[N]) % 1000000009) + p3[N]) % 1000000009 << std::endl;
	}
	return 0;
}