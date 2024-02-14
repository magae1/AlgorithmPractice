#include <iostream>
using namespace std;

bool checker[246913];

int main() {
	int n, m;
	int prn;
	do {
		for (int i = 1; i <= 246912; i++)
			checker[i] = false;
		cin >> n;
		if (n == 0)
			break;
		m = 2 * n;
		prn = n;
		for (int j = n + 1; j <= m; j++) {
			if (checker[j] == false) {
				for (int div = 2; div * div <= j; div++) {
					if (j % div == 0) {
						checker[j] = true;
						prn--;
						break;
					}
				}
			}
		}
		printf("%d\n", prn);
	} while (n > 0);
	return 0;
}