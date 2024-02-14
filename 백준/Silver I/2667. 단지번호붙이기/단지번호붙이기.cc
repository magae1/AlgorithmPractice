#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

char map[25][25];
bool mapschecker[25][25];
std::vector<std::pair<int, int>> mapnode;

bool func(std::pair<int, int>p1, std::pair<int, int>p2) {
	if (p1.first == p2.first) {
		if (p1.second == p2.second + 1)
			return true;
		if (p1.second == p2.second - 1)
			return true;
	}
	if (p1.second == p2.second) {
		if (p1.first == p2.first + 1)
			return true;
		if (p1.first == p2.first - 1)
			return true;
	}
	return false;
}

int main() {
	int N;
	int count = 0;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> map[i];
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1')
				mapnode.push_back({ i, j });
		}
	}
	std::queue<std::pair<int, int>> qu;
	std::vector<int>place;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1' && mapschecker[i][j] == false) {
				int subcount = 0;
				count++;
				qu.push({ i, j });
				while (!qu.empty()) {
					auto quface = qu.front();
					mapschecker[quface.first][quface.second] = true;
					subcount++;
					qu.pop();
					for (auto it = mapnode.begin(); it < mapnode.end(); it++) {
						int it_row = (*it).first, it_col = (*it).second;
						if (mapschecker[it_row][it_col] == false && func(quface, *it)) {
							qu.push(*it);
							mapschecker[it_row][it_col] = true;
						}
					}
				}
				place.push_back(subcount);
			}
		}
	}
	std::cout << count << std::endl;
	std::sort(place.begin(), place.end());
	for (auto it = place.begin(); it < place.end(); it++)
		std::cout << *it << std::endl;
	return 0;
}