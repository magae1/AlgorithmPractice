#include <iostream>

bool c[10];
int a[10];
void go(int index, int n, int m) {
	if (index == m) { 
		for (int i = 0; i < index; i++)
			printf("%d ", a[i]);
		printf("\n");
	}

	for (int i = 1; i <= n; i++) {
		if (c[i])
			continue;
		c[i] = true;
		a[index] = i;
		go(index + 1, n, m);
		c[i] = false;
	}
}

int main() {
	int N, M;
	std::cin >> N >> M;
	go(0, N, M);
	return 0;
}