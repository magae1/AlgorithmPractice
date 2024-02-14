#include <iostream>
#include <algorithm>

int main() {
	long long twocount = 0;
	long long fivecount = 0;
	long long N, M;
	std::cin >> N >> M;
	for (long long i = 2; i <= N; i *= 2)
		twocount += N / i;
	for (long long i = 2; i <= N - M; i *= 2)
		twocount -= (N - M) / i;
	for (long long i = 2; i <= M; i *= 2)
		twocount -= M / i;
	for (long long i = 5; i <= N; i *= 5)
		fivecount += N / i;
	for (long long i = 5; i <= N - M; i *= 5)
		fivecount -= (N - M) / i;
	for (long long i = 5; i <= M; i *= 5)
		fivecount -= M / i;
	std::cout << std::min(twocount, fivecount) << std::endl;
	return 0;
}