#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
int edgechecker[101][101];
std::vector <std::pair<int, int>> edges;
bool Canitmove(std::pair <int, int> p1, std::pair<int, int>p2) {
	if (p1.first == p2.first) {
		if (p1.second + 1 == p2.second)
			return true;
		else if (p1.second - 1 == p2.second)
			return true;
	}
	else if (p1.second == p2.second) {
		if (p1.first + 1 == p2.first)
			return true;
		else if (p1.first - 1 == p2.first)
			return true;
	}
	return false;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		std::string str;
		std::cin >> str;
		for (int j = 0; j < M; j++) {
			if (str[j] == '1') {
				edges.push_back({ i + 1, j + 1 });
			}
		}
	}
	std::queue <std::pair<int, int>> qu;
	qu.push({ 1, 1 });
	edgechecker[1][1] = 1;
	while (!qu.empty()) {
		auto frontit = qu.front();
		int count = edgechecker[frontit.first][frontit.second];
		qu.pop();
		for (auto it = edges.begin(); it < edges.end(); it++) {
			int itfst = (*it).first;
			int itsec = (*it).second;
			if (edgechecker[itfst][itsec] == 0) {
				if (Canitmove(frontit, *it)) {
					edgechecker[itfst][itsec] = count + 1;
					qu.push(*it);
				}
			}
		}
	}
	std::cout << edgechecker[N][M];
	return 0;
}