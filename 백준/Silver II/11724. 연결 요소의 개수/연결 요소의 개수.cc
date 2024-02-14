#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

bool edgescontain[1001][1001];
std::vector<int>edges_of_a_node[1001];

bool nodechecker[1001];
int main() {
	int N, M;
	std::cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		edgescontain[from][to] = true;
		edgescontain[to][from] = true;
		edges_of_a_node[from].push_back(to);
		edges_of_a_node[to].push_back(from);
	}

	std::queue <int> qu;
	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (nodechecker[i] == false) {
			qu.push(i);
			nodechecker[i] = true;
			while (!qu.empty()) {
				int facenum = qu.front();
				qu.pop();
				for (auto it = edges_of_a_node[facenum].begin(); it < edges_of_a_node[facenum].end(); it++) {
					if (nodechecker[*it] == false) {
						qu.push(*it);
						nodechecker[*it] = true;
					}			
				}
			}
			count++;
		}
	}
	std::cout << count;
	return 0;
}