#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

	int in_num[10];
	int check_num[42] = { 0 };
	int n = 0;

	for (int i = 0; i <= 9; i++) {
		scanf("%d", &in_num[i]);

		check_num[in_num[i] % 42] = 1;

	}

	for (int j = 0; j < 42; j++) {
		if (check_num[j] == 1) {
			n++;
		}
	}

	printf("%d", n);

	return 0;
}