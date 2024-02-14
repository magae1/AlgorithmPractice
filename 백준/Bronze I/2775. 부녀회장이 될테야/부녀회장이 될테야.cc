#include <iostream>
using namespace std;

int main(void) {
	int CaseTest;
	cin >> CaseTest;
	while (CaseTest--) {
		int apart[15];
		for (int i = 0; i < 15; i++)
			apart[i] = i;
		int k, n;
		cin >> k >> n;
		for (int i = 1; i <= k; i++) {
			for (int j = n; j > 0; j--) {
				for (int t = j - 1; t > 0; t--) {
					apart[j] += apart[t];
				}
			}
		}
		printf("%d\n", apart[n]);
	}
	return 0;
}