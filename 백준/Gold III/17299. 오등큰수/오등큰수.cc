#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<stack>
int numcount[1000001];

int main() {
	int N;
	std::cin >> N;
	std::vector<int> sequenceA(N);
	std::vector<int> result(N);
	std::stack<int> positions, countstk;
	for (int i = 0; i < N; i++) {
		int s;
		scanf("%d", &s);
		sequenceA[i] = s;
		numcount[s] += 1;
	}
	for (int i = 0; i < N; i++) {
		int curnumcount = numcount[sequenceA[i]];
		if (positions.empty()) {
			positions.push(i);
			countstk.push(curnumcount);
		}
		else {
			while (!positions.empty()) {
				if (countstk.top() < curnumcount) {
					result[positions.top()] = sequenceA[i];
					positions.pop();
					countstk.pop();
				}
				else
					break;
			}
			positions.push(i);
			countstk.push(curnumcount);
		}
	}
	while (!positions.empty()) {
		result[positions.top()] = -1;
		positions.pop();
	}
	for (int i = 0; i < N; i++)
		printf("%d ", result[i]);
	return 0;
}