#include<stdio.h>
#define HOW_MANY 9

int main() {
	
	int n, max;
	int count = 0;
	int floor = 1;

	for (int i = 0; i < HOW_MANY; i++) {
		scanf("%d", &n);
		count++;
		if (i == 0) {
			max = n;
		}
		else {
			if (n > max) {
				max = n;
				floor = count;
			}
		}
	}
	
	printf("%d\n%d", max, floor);

	return 0;
}
