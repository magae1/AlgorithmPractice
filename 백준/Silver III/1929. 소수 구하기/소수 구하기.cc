#include <iostream>
using namespace std;

bool check[1000001];

int main() {
	int M, N;
	check[1] = true;
	cin >> M >> N;
	for (int num = M; num <= N; num++) {
		for (int div = 2; div * div <= num; div++) {
			if (check[num] == false) {
				if (num % div == 0)
					check[num] = true;
			}
		}
	}
	for (int i = M; i <= N; i++) {
		if (check[i] == false)
			printf("%d\n", i);
	}
	return 0;
}