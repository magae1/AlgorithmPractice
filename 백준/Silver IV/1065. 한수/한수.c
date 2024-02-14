#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int d(int a);

int main() {
	
	int num;
	int sum = 0;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		sum = sum + d(i);
	}

	printf("%d", sum);
	return 0;
}


int d(int a) {
	int x, y, z;

	if (a > 99) {
		x = a / 100;
		y = (a - x * 100) / 10;
		z = (a - (x * 100 + y * 10));
		if (x+z == 2*y){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		return 1;
	}
}

