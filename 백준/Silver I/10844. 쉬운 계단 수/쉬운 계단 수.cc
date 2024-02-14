#include <iostream>

long long p[10][101];

int main() {
	for (int i = 1; i <= 9; i++)
		p[i][1] = 1;
	int N;
	std::cin >> N;
	for (int i = 2; i <= N; i++) {
		p[0][i] = p[1][i - 1];
		for (int j = 1; j <= 8; j++)
			p[j][i] = (p[j - 1][i - 1] + p[j + 1][i - 1]) % 1000000000;
		p[9][i] = p[8][i - 1];
	}
	long long result = 0;
	for (int i = 0; i <= 9; i++)
		result = (result + p[i][N]) % 1000000000;
	std::cout << result;
 	return 0;
}