#include <iostream>
#include <vector>
#include <queue>


int main() {
	std::vector<std::pair<int, int>> moving = { {1, 2}, {2, 1}, {2, -1}, {-1, 2}, {-2, 1}, {1, -2}, {-1, -2}, {-2, -1} };
	int T;
	std::cin >> T;
	while (T--) {
		std::queue<std::pair<int, int>> qu;
		int chesssize, src_row, src_col, des_row, des_col;
		std::cin >> chesssize;
		std::vector<std::vector<int>> ChessBoard(chesssize, std::vector<int>(chesssize, -1));
		std::cin >> src_row >> src_col;
		std::cin >> des_row >> des_col;
		std::pair<int, int>src = { src_row, src_col };
		std::pair<int, int> des = { des_row, des_col };
		qu.push(src);
		ChessBoard[src.first][src.second] = 0;
		while (!qu.empty()) {
			auto qu_front = qu.front();
			qu.pop();
			for (int i = 0; i < 8; i++) {
				std::pair<int, int> nextPos = { qu_front.first + moving[i].first, qu_front.second + moving[i].second };
				if (nextPos.first >= 0 && nextPos.first < chesssize && nextPos.second >= 0 && nextPos.second < chesssize) {
					if (ChessBoard[nextPos.first][nextPos.second] < 0) {
						ChessBoard[nextPos.first][nextPos.second] = ChessBoard[qu_front.first][qu_front.second] + 1;
						qu.push(nextPos);
					}
				}
			}
			if (ChessBoard[des.first][des.second] >= 0)
				break;
		}
		std::cout << ChessBoard[des.first][des.second] << '\n';
	}
	return 0;
} 