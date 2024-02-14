#include <iostream>
#include <vector>
#include <queue>

bool IsLandClosed(std::pair<int, int> origin, std::pair<int, int> des) {
	if (des.first >= origin.first - 1 && des.first <= origin.first + 1) {
		if (des.second >= origin.second - 1 && des.second <= origin.second + 1)
			return true;
	}
	return false;
}

int main() {
	int w, h;
	do {
		std::cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		std::vector<std::vector<int>> Map(h, std::vector<int>(w, 0));
		std::vector<std::vector<bool>> Checker(h, std::vector<bool>(w, false));
		std::vector<std::pair<int, int>> LandCoordinate;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				int a;
				std::cin >> a;
				if (a == 1) {
					LandCoordinate.push_back({ i, j });
					Map[i][j] = 1;
				}
			}
		}
		int IslandCount = 0;
		for (auto it = LandCoordinate.begin(); it < LandCoordinate.end(); it++) {
			if (Checker[(*it).first][(*it).second] == false) {
				std::queue<std::pair<int, int>> qu;
				qu.push(*it);
				Checker[(*it).first][(*it).second] = true;
				while (!qu.empty()) {
					auto qu_front = qu.front();
					qu.pop();
					for (auto qu_it = LandCoordinate.begin(); qu_it < LandCoordinate.end(); qu_it++) {
						if (Checker[(*qu_it).first][(*qu_it).second] == false && IsLandClosed(qu_front, *qu_it)) {
							qu.push(*qu_it);
							Checker[(*qu_it).first][(*qu_it).second] = true;
						}
					}
				}
				IslandCount++;
			}
		}
		std::cout << IslandCount << std::endl;
	} while (w != 0 && h != 0);
	return 0;
}