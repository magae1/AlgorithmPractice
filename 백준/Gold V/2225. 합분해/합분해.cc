#include <iostream>
#include <vector>

int main() {
	int N, K;
	std::cin >> N >> K;
	std::vector < std::vector<long long>> nentries(N + 1, std::vector<long long>(K + 1, 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= K; j++) {
			nentries[i][j] = 0;
			for (int z = 0; z <= i; z++) {
				nentries[i][j] = (nentries[i][j] + nentries[z][j - 1]) % 1000000000;
			}
		}
	}
	std::cout << nentries[N][K];
	return 0;
}