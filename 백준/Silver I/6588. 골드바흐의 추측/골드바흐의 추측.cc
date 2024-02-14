#include <iostream>

bool primenums[1000001];

int main() {
	int N = -1;
	for (int i = 3; i * i <= 1000000; i += 2) {
		if (primenums[i] == false) {
			int mult = 2;
			while (i * mult <= 1000000) {
				primenums[i * mult] = true;
				mult++;
			}
		}
	}
	while(N != 0) {
		scanf("%d", &N);
		if (N == 0)
			break;
		int a = 3;
		bool ch = false;
		while (a <= (N >> 1)) {
			if (!primenums[a] && !primenums[N - a]) {
				ch = true;
				break;
			}
			else {
				a += 2;
			}
		}
		if (ch)
			printf("%d = %d + %d\n", N, a, N - a);
		else
			printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}