#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

	int nu,score;
	int total_score = 0;
	int highest_score = 0;

	scanf("%d", &nu);

	for (int i = 0; i < nu; i++) {
		scanf("%d", &score);
		total_score = total_score + score;
		if (highest_score < score) {
			highest_score = score;
		}
	}

	printf("%lf", (double)total_score / nu / highest_score * 100);

	return 0;
}