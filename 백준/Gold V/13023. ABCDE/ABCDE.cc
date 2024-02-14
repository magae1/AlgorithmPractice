#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

bool Relationship[2000][2000];
std::vector<int> g[2000];
std::vector<std::pair<int, int>> edges;
int main() {
	int N, M;
	std::cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		std::cin >> A >> B;
		edges.push_back({ A, B });
		edges.push_back({ B, A });
		Relationship[A][B] = true;
		Relationship[B][A] = true;
		g[A].push_back(B);
		g[B].push_back(A);
	}
	M *= 2;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			int A = edges[i].first;
			int B = edges[i].second;
			int C = edges[j].first;
			int D = edges[j].second;
			if (A == B || A == C || A == D || B == C || B == D || C == D)
				continue;
			if (Relationship[B][C] == false)
				continue;

			for (int E : g[D]) {
				if (A == E || B == E || C == E || D == E)
					continue;
				std::cout << 1 << '\n';
				return 0;
			}
		}
	}

	std::cout << 0 << '\n';
	return 0;
}