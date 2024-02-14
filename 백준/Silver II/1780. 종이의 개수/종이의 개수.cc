#include <iostream>

int ch[2187][2187];

void fuc(int ch[2187][2187], int x, int y, int n, int* num) {
	int color = ch[x][y];
	bool checker = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ch[x + i][y + j] != color) {
				int buf = n / 3;
				for (int t = 0; t < 3; t++) {
					for (int k = 0; k < 3; k++) {
						fuc(ch, x + buf * t, y + buf * k, buf, num);
					}
				}
				checker = true;
				break;
			}
		}
		if (checker)
			break;
	}
	if (!checker) {
		if (color == -1)
			num[0] += 1;
		else if (color == 0)
			num[1] += 1;
		else if (color == 1)
			num[2] += 1;
	}
}

int main() {
	int N;
	int col[3] = { 0, 0, 0 };
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			std::cin >> ch[i][j];
	}
	fuc(ch, 0, 0, N, col);
	for (int i = 0; i < 3; i++)
		std::cout << col[i] << std::endl;
	return 0;
}