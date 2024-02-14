#include <iostream>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	int quotient = N / 5;
	int result = -1;
	while (quotient >= 0) {
		int remainder = N - (5 * quotient);
		if (remainder % 3 == 0) {
			result = (remainder / 3) + quotient;
			break;
		}
		quotient--;
	}
	printf("%d\n", result);
	return 0;
}