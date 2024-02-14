#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int table_case = 0;
	int n, k;
	char arr[20];

	scanf("%d", &table_case);

	for (int i = 0; i < table_case; i++) {
		scanf("%d", &n);
		scanf("%s", arr);
		k = 0;
		while (arr[k] != '\0') {
			for (int j = 0; j < n; j++) 
				printf("%c", arr[k]);
			k++;
		}
		printf("\n");
	}
	return 0;
}