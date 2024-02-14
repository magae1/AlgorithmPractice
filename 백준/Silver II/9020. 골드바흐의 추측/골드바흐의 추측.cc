#include <iostream>
using namespace std;

bool checker[10001];

int main() {
	int T;
	int n;
	int fst_n = 0, sec_n = 0;

	for (int num = 1; num <= 10000; num++) {
		for (int div = 2; div * div <= num; div++) {
			if (num % div == 0) {
				checker[num] = true;
				break;
			}
		}
	}
	cin >> T;
	while (T--) {
		cin >> n;
		for (sec_n = n >> 1; sec_n <= n - 2; sec_n++) {
			fst_n = n - sec_n;
			if (!checker[sec_n] && !checker[fst_n])
				break;
		}
		printf("%d %d\n", fst_n, sec_n);
	}
	return 0;
}