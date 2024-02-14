#include <iostream>
int main(void) {
	int A, B, V;
	int result;
	scanf("%d %d %d", &A, &B, &V);
	if (V <= A)
		result = 1;
	else {
		if ((V - A) % (A - B) != 0)
			result = (V - A) / (A - B) + 2;
		else
			result = (V - A) / (A - B) + 1;
	}
	printf("%d\n", result);
	return 0;
}