#include <iostream>
#include <algorithm>
int HowManyChangeColor_of_EightbyEight_ChessBoard(char chessboard[50][50], int x, int y) {
	int changenum_towhite = 0;
	int changenum_toblack = 0;
	char whiteblock = 'W';
	char blackblock = 'B';
	for (int y_pos = 0; y_pos < 8; y_pos++) {
		for (int x_pos = 0; x_pos < 8; x_pos++) {
			if ((x_pos + y_pos) % 2 == 0) {
				if (chessboard[y + y_pos][x + x_pos] == 'W')
					changenum_toblack++;
				else
					changenum_towhite++;
			}
			else {
				if (chessboard[y + y_pos][x + x_pos] == 'W')
					changenum_towhite++;
				else
					changenum_toblack++;
			}
		}
	}
	return std::min(changenum_toblack, changenum_towhite);
}

int main() {
	int N, M;
	char chessboard[50][50];
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		std::cin >> chessboard[i];
	}
	int min_size = 32;
	for (int y = 0; y <= N - 8; y++) {
		for (int x = 0; x <= M - 8; x++) {
			int buf_times = HowManyChangeColor_of_EightbyEight_ChessBoard(chessboard, x, y);
			min_size = std::min(min_size, buf_times);
		}
	}
	std::cout << min_size << std::endl;
	return 0;
}