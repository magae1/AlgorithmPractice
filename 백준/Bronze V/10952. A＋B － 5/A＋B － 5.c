#include<stdio.h>

int main() {
	int x_1, x_2;
	do{
		scanf("%d %d", &x_1, &x_2);
		if ((x_1 == 0) && (x_2 == 0)) {
			break;
		}
		printf("%d\n", x_1 + x_2);

	} while (1);

	return 0;
}