#include<stdio.h>

int main() {
	int n;
	do {
	scanf("%d", &n);
	if (n >= 1 && n <= 100)
		break;
	} while (1);


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if ((n - j) >= i) {
				printf(" ");
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}

	return 0;
}