#include<stdio.h>
#include<stdlib.h>

int main() {
	int t;
	scanf("%d", &t);
	int* case_1 = (int*)malloc(sizeof(int) * t);
	int* case_2 = (int*)malloc(sizeof(int) * t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &case_1[i], &case_2[i]);
	}

	for (int j = 0; j < t; j++) {
		printf("Case #%d: %d\n", (j + 1), (case_1[j] + case_2[j]));
	}
	return 0;
}