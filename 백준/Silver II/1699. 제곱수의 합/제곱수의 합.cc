#include <iostream>

int acount[100001];

int main() {
	int N;
	std::cin >> N;
	for (int i = 1; i * i <= N; i++)
		acount[i * i] = 1;
	for (int i = 1; i <= N; i++) {
		if (acount[i] == 0) {
			acount[i] = i;
			for (int j = 1; j * j <= i; j++) {
				if (acount[i] > acount[j * j] + acount[i - (j * j)])
					acount[i] = acount[j * j] + acount[i - (j * j)];
			}
		}		
	}
	std::cout << acount[N];
	return 0;
}