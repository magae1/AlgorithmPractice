#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

bool nodewavechecker[1001];
int edgecontain1[1001][1001];
int edgecontain2[1001][1001];
std::vector<int> nums_of_node[1001];
std::vector<std::pair<int, int>> edges;

void DFS(int x) {
	nodewavechecker[x] = true;
	printf("%d ", x);
	for (auto it = nums_of_node[x].begin(); it < nums_of_node[x].end(); it++) {
		if (nodewavechecker[*it] == false && edgecontain1[x][*it] > 0) {
			edgecontain1[x][*it] -= 1;
			DFS(*it);
		}
	}
}

int main() {
	int N, M, startvertex;
	std::cin >> N >> M >> startvertex;
	for (int i = 0; i < M; i++) {
		int from, to;
		std::cin >> from >> to;
		edges.push_back({ from, to });
		edges.push_back({ to, from });
		edgecontain1[from][to] += 1;
		edgecontain1[to][from] += 1;
		edgecontain2[from][to] += 1;
		edgecontain2[to][from] += 1;
		nums_of_node[from].push_back(to);
		nums_of_node[to].push_back(from);
	}
	for (int i = 1; i <= 1000; i++)
		std::sort(nums_of_node[i].begin(), nums_of_node[i].end());
	DFS(startvertex);
	printf("\n");
	for (int i = 1; i <= 1000; i++)
		nodewavechecker[i] = false;

	std::queue<int> qu;
	nodewavechecker[startvertex] = true;
	qu.push(startvertex);
	while (!qu.empty()) {
		int x = qu.front();
		printf("%d ", x);
		qu.pop();
		for (auto it = nums_of_node[x].begin(); it < nums_of_node[x].end(); it++) {
			if (nodewavechecker[*it] == false && edgecontain2[x][*it] > 0) {
				edgecontain2[x][*it] -= 1;
				nodewavechecker[*it] = true;
				qu.push(*it);
			}
		}
	}
	return 0;
}