#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {

	int case_num = 0;
	int student_num = 0;
	int case_score = 0;
	double avgscr_per_case = 0;
	int n = 0;

	scanf("%d", &case_num);

	for (int i = 0; i < case_num; i++) {
		int case_num = 0;
		int student_num = 0;
		int case_score = 0;
		double avgscr_per_case = 0;
		int n = 0;

		scanf("%d", &student_num);
		int* student_score = (int*)malloc(sizeof(int) * student_num);

		for (int j = 0; j < student_num; j++) {
			scanf("%d", &student_score[j]);
			case_score = case_score + student_score[j];
		}
		avgscr_per_case = (double)case_score / student_num;

		for (int k = 0; k < student_num; k++) {
			if (avgscr_per_case < student_score[k]) {
				n++;
			}

		}
		printf("%.3lf%c\n", (double)n / student_num*100,'%');
	}
	return 0;
}