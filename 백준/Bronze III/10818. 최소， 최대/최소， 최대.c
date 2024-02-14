#include<stdio.h>
#include<stdlib.h>

int main() {
	
	int n, k, max, low;

	do {
		scanf("%d", &n);
	} while (n <= 0 || n > 1000000);


	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		if (i == 1) {
			max = k;
			low = k;
		}
		else {
			if (k > max) {
				max = k;
			}
			else if (k < low) {
				low = k;
			}
		}

	}

	printf("%d %d", low, max);

	return 0;
}
