#include<stdio.h>

int main() {
	int n, x_1,x_2;	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x_1, &x_2);
		printf("%d\n", x_1 + x_2);
	}

	return 0;
}