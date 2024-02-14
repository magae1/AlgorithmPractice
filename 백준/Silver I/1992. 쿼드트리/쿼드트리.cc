#include <iostream>

void fuc(char ch[64][65], int x, int y, int n) {
	char color = ch[x][y];
	bool checker = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ch[x + i][y + j] != color) {
				checker = true;
				break;
			}
		}
		if (checker)
			break;
	}
	if (!checker)
		std::cout << color;
	else {
		std::cout << '(';
		fuc(ch, x, y, n >> 1);
		fuc(ch, x, y + (n >> 1), n >> 1);
		fuc(ch, x + (n >> 1), y, n >> 1);
		fuc(ch, x + (n >> 1), y + (n >> 1), n >> 1);
		std::cout << ')';
	}
	
}

int main() {
	int N;
	char ch[64][65];
	std::cin >> N;
	for (int i = 0; i < N; i++)
		std::cin >> ch[i];
	fuc(ch, 0, 0, N);
	return 0;
}