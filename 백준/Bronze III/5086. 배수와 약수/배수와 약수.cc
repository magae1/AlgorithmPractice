#include <iostream>
using namespace std;

int main(void) {
	int num1, num2;
	while (1) {
		cin >> num1 >> num2;
		if (num1 == 0 && num2 == 0)
			return 0;
		switch (num1 > num2) {
		case 1:
			if (num1 % num2 == 0) {
				printf("multiple\n");
				break;
			}
		case 0:
			if (num2 % num1 == 0) {
				printf("factor\n");
				break;
			}
		default:
			printf("neither\n");
			break;
		}
	}
}