#include<stdio.h>

int main() {
	int x_c, x, y, z;
	int count = 0;

	do {
		scanf("%d", &x_c);
	} while (x_c < 0 || x_c > 99);

	x = x_c;

	do {
		if (x < 10) {
			y = x;
			z = x;
		}
		else {
			y = x % 10;
			z = (x/10+y)%10;
		}
		x = 10 * y + z;
		count++;
	} while (x != x_c);

	printf("%d", count);

	return 0;
}
