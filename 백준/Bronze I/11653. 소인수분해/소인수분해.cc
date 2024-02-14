#include <iostream>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	int subsub = 2;
	while (T > 1) {
		if (T % subsub == 0) {
			T = T / subsub;
			printf("%d\n", subsub);
		}
		else {
			subsub += 1;
		}
	}
	return 0;
}