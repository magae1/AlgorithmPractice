#include <iostream>

int nums[10];
void go(int index, int start, int n, int m) {
	if (index == m) {
		for (int i = 0; i < index; i++)
			printf("%d ", nums[i]);
		printf("\n");
		return;
	}
	for (int i = start; i <= n; i++) {
		nums[index] = i;
		go(index + 1, i, n, m);
	}
}

int main() {
	int N, M;
	std::cin >> N >> M;
	go(0, 1, N, M);
	return 0;
}