#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include <vector>
#include <queue>

int groupnum_of_node[20001];
std::vector <int> edges_of_a_node[20001];

int main() {
	int K;
	std::cin >> K;
	for (int t = 0; t < K; t++){
		int V, E;
		bool strchecker = false;
		scanf("%d %d", &V, &E);
		for (int i = 1; i <= V; i++) {
			groupnum_of_node[i] = 0;
			edges_of_a_node[i].clear();
		}
		for (int i = 0; i < E; i++) {
			int from, to;
			scanf("%d %d", &from, &to);
			edges_of_a_node[from].push_back(to);
			edges_of_a_node[to].push_back(from);
		}
		
		for (int a = 1; a <= V; a++) {
			if (groupnum_of_node[a] == 0) {
				std::queue <int> qu;
				qu.push(a);
				groupnum_of_node[a] = 1;
				while (!qu.empty()) {
					int numbface = qu.front();
					qu.pop();
					for (auto it = edges_of_a_node[numbface].begin(); it < edges_of_a_node[numbface].end(); it++) {
						if (groupnum_of_node[numbface] == 1) {
							if (groupnum_of_node[*it] == 0) {
								groupnum_of_node[*it] = 2;
								qu.push(*it);
							}
							else if (groupnum_of_node[*it] == 1) {
								strchecker = true;
							}
						}
						else if (groupnum_of_node[numbface] == 2) {
							if (groupnum_of_node[*it] == 0) {
								groupnum_of_node[*it] = 1;
								qu.push(*it);
							}
							else if (groupnum_of_node[*it] == 2) {
								strchecker = true;
							}
						}
					}
				}
			}
		}
		if (strchecker == false)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}