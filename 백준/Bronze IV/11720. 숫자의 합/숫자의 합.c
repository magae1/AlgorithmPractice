#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int size = 0;
	int sum = 0;

	scanf("%d", &size);
	char* numarr = (char*)malloc(size+1);
	memset(numarr, 0, sizeof(numarr));
	
	scanf("%s", numarr, sizeof(numarr));
	
	for (int i = 0; i < size; i++) 
		sum = sum + ((int)*(numarr + i) - 48);
		
	printf("%d", sum);


	return 0;
}