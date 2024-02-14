#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	char arr[100] = { '\0' };
	int n = 0;
	int alph[26];

	scanf("%s", &arr);


	for (int i = 0; i < 26; i++) {
		n = 0;
		alph[i] = -1;

		while (arr[n] != '\0') {
			if ((int)arr[n] - 97 == i) {
				alph[i] = n;
				break;
			}
			n++;
		}

		printf("%d ", alph[i]);
	}

	return 0;
}