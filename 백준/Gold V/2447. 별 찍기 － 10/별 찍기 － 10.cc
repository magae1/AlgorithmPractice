#include <iostream>

char Pearls[6562][6562];

void func(char stars[6562][6562], int x, int y, int n) {
	if (n == 1) {
		stars[y][x] = '*';
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != 1 || j != 1)
				func(stars, x + j * (n / 3), y + i * (n / 3), n / 3);
		}
	}
}

int main() {
	int N; 
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			Pearls[i][j] = ' ';
	}
	func(Pearls, 0, 0, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%c", Pearls[i][j]);
		printf("\n");
	}

	return 0;
}