#include <iostream>
using namespace std;

int* max(int* a, int*b) {
	if (*a > *b)
		return a;
	else
		return b;
}

int main() {
	int a, b, c;
	int* heru = NULL;
	int* ausar = NULL;
	int* auset = NULL;
	do {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;
		heru = max(max(&a, &b), &c);
		if (heru == &a) {
			ausar = &b;
			auset = &c;
		}
		else if (heru == &b) {
			ausar = &a;
			auset = &c;
		}
		else {
			ausar = &a;
			auset = &b;
		}
		if ((*heru) * (*heru) == (*ausar) * (*ausar) + (*auset) * (*auset))
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	} while (a > 0 && b > 0 && c > 0);
	return 0;
}