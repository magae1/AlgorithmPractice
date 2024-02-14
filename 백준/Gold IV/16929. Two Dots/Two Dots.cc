#include <iostream>
#include <vector>
#include <stack>

int main() {
	char DotsBoard[50][51];
	std::vector<std::pair<int, int>>moving = { {1, 0}, {0, 1}, {0, -1}, {-1, 0} };
	int N, M;
	std::cin >> N >> M;
	std::vector<std::vector<bool>> DotsChecker(N, std::vector<bool>(M, false));
	for (int i = 0; i < N; i++)
		std::cin >> DotsBoard[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::stack<std::pair<int, int>> stk;
			DotsChecker[i][j] = true;
			std::pair<int, int>startpos = { i, j };
			stk.push(startpos);
			while (!stk.empty()) {
				auto toppos = stk.top();
				bool IsitPush = false;
				for (int t = 0; t < 4; t++) {
					std::pair<int, int>nextpos = { toppos.first + moving[t].first , toppos.second + moving[t].second };
					if (nextpos.first >= 0 && nextpos.first < N && nextpos.second >= 0 && nextpos.second < M) {
						if (DotsBoard[nextpos.first][nextpos.second] == DotsBoard[toppos.first][toppos.second]) {
							if (DotsChecker[nextpos.first][nextpos.second] == false) {
								DotsChecker[nextpos.first][nextpos.second] = true;
								IsitPush = true;
								stk.push(nextpos);
								if (stk.size() >= 4) {
									for (int y = 0; y < 4; y++) {
										if ((startpos.first + moving[y].first == nextpos.first) && (startpos.second + moving[y].second == nextpos.second)) {
											std::cout << "Yes";
											return 0;
										}
									}
								}
								break;
							}
						}
					}					
				}
				if (!IsitPush)
					stk.pop();
			}
			for (int q = 0; q < N; q++) {
				for (int p = 0; p < M; p++)
					DotsChecker[q][p] = false;
			}
		}
	}
	std::cout << "No";
	return 0;
} 