#include <iostream>

void fuc(int ch[128][128], int x, int y, int n, int* white, int* blue) {
	int color = ch[x][y];
	bool checker = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ch[x + i][y + j] != color) {
				fuc(ch, x, y, n >> 1, white, blue);
				fuc(ch, x + (n >> 1), y, n >> 1, white, blue);
				fuc(ch, x, y + (n >> 1), n >> 1, white, blue);
				fuc(ch, x + (n >> 1), y + (n >> 1), n >> 1, white, blue);
				checker = true;
				break;
			}
		}
		if (checker)
			break;
	}
	if (!checker) {
		if (color == 1)
			(*blue) += 1;
		else
			(*white) += 1;
	}
}

int main() {
	int N;
	int blueone = 0;
	int whiteone = 0;
	int papers[128][128];
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			std::cin >> papers[i][j];
	}
	fuc(papers, 0, 0, N, &whiteone, &blueone);
	std::cout << whiteone << '\n' << blueone << '\n';
	return 0;
}