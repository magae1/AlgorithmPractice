#include <iostream>
using namespace std;

int main(void) {
	int CaseTest;
	cin >> CaseTest;
	while (CaseTest--) {
		int H, W, N;
		cin >> H >> W >> N;
		int quotient = N / H;
		int remainder = N % H;
		if (remainder == 0) {
			remainder = H;
			quotient -= 1;
		}
		printf("%d\n", (remainder * 100) + (quotient + 1));
	}
	return 0;
}