#include <stdio.h>
int self_number(int);
int main() {

	for (int i = 1; i < 10000; i++) {
		if (self_number(i) == 0) {
			printf("%d\n", i);
		}
	}

	return 0;
}

int self_number(int num) {
	int i = 0;
	int n[4];
	while (i < num) {
		n[0] = i / 1000;
		n[1] = (i - n[0] * 1000) / 100;
		n[2] = (i - n[0] * 1000 - n[1] * 100) / 10;
		n[3] = i - n[0] * 1000 - n[1] * 100 - n[2] * 10;
		if ((n[0] + n[1] + n[2] + n[3] + i) == num)
			return 1;
		
		i++;
	}
	return 0;
}