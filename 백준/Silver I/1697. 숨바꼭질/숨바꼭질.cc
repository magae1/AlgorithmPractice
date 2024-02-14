#include <iostream>
#include <vector>
#include <queue>

int main() {
	const int MAX = 100001;
	int N, K;
	std::cin >> N >> K;
	std::vector<int> spendingtime(MAX, 0);
	std::vector<bool> pointchecker(MAX, false);
	std::queue<int> qu;
	qu.push(N);
	pointchecker[N] = true;
	while (!qu.empty()) {
		int currentpoint = qu.front();
		qu.pop();
		if (currentpoint * 2 < MAX) {
			if (pointchecker[currentpoint * 2] == false) {
				pointchecker[currentpoint * 2] = true;
				spendingtime[currentpoint * 2] = spendingtime[currentpoint] + 1;
				qu.push(currentpoint * 2);
			}
		}
		if (currentpoint + 1 < MAX) {
			if (pointchecker[currentpoint + 1] == false) {
				pointchecker[currentpoint + 1] = true;
				spendingtime[currentpoint + 1] = spendingtime[currentpoint] + 1;
				qu.push(currentpoint + 1);
			}			
		}
		if (currentpoint - 1 >= 0) {
			if (pointchecker[currentpoint - 1] == false) {
				pointchecker[currentpoint - 1] = true;
				spendingtime[currentpoint - 1] = spendingtime[currentpoint] + 1;
				qu.push(currentpoint - 1);
			}
		}
		if (spendingtime[K] > 0)
			break;
	}
	std::cout << spendingtime[K];
	return 0;
}