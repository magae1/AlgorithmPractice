#include <iostream>
using namespace std;

int psstack[100000];

int psps(int n) {
	if (n < 2) {
		return 0;
	}
	else {
		if (psstack[n] > 0)
			return psstack[n];
		else {
			psstack[n] = psstack[n - 1] + n;
			return psstack[n];
		}
	}
}

int main(void) {
	int N;
	cin >> N;

	if (N == 1) {
		printf("1\n");
	}
	else if (N < 8) {

		printf("2\n");
	}
	else {
		int quotient = (N - 2) / 6;
		int i = 1;
		while (i < 100000) {
			if (psps(i - 1) < quotient && psps(i) >= quotient)
				break;
			i++;
		}
		printf("%d\n", i + 1);
	}
	return 0;
}