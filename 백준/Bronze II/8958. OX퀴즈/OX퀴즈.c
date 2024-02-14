#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {

	int num = 0;
	int min_score = 0;
	int n = 0;
	char str[80];

	scanf("%d", &num);

	int* total_score = (int*)malloc(sizeof(int) * num);

	for (int i = 0; i < num; i++) {
		scanf("%s", str);
		total_score[i] = 0;
		min_score = 0;
		for (int j = 0; str[j] != '\0'; j++) {
			if (str[j] == 'X') {
				min_score = 0;
			}
			else if (str[j] == 'O') {
				min_score++;
				total_score[i] = total_score[i] + min_score;
			}
		}
	}

	for (int k = 0; k < num; k++) {
		printf("%d\n", total_score[k]);
	}

	return 0;
}