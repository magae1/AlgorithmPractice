#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int x_1, x_2;
	while (scanf("%d %d",&x_1,&x_2) != EOF) {
		printf("%d\n", x_1 + x_2);
	}

	return 0;
}