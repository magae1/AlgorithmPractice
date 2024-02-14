#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

	int a, b, c;
	int sum;
	char s1[9];
	int s2[10] = { 0 };
	do {
		scanf("%d %d %d", &a, &b, &c);
	} while (a < 100 && b < 100 && c < 100 && a>999 && b>999 && c>999);

	sum = a * b * c;

	sprintf(s1, "%d", sum);
	
	for (int i = 0; i < 10; i++) {
		switch (s1[i]){
		case '0' :
			s2[0]++;
			break;
		case '1':
			s2[1]++;
			break;
		case '2':
			s2[2]++;
			break;
		case '3':
			s2[3]++;
			break;
		case '4':
			s2[4]++;
			break;
		case '5':
			s2[5]++;
			break;
		case '6':
			s2[6]++;
			break;
		case '7':
			s2[7]++;
			break;
		case '8':
			s2[8]++;
			break;
		case '9':
			s2[9]++;
			break;
		}
	}

	for (int j = 0; j < 10; j++) {
		printf("%d\n", s2[j]);
	}

	return 0;
}