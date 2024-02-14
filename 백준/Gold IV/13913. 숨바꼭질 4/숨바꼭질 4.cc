#include <iostream>
#include <vector>
#include <queue>
#include <stack>

int main() {
	const int MAX = 100001;
	int N, K;
	std::cin >> N >> K;
	std::vector<int> spendingtime(MAX, 0);
	std::vector<bool> pointchecker(MAX, false);
	std::vector<int> footpoint(MAX, 0);
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
				footpoint[currentpoint * 2] = currentpoint;
				qu.push(currentpoint * 2);
			}
		}
		if (currentpoint + 1 < MAX) {
			if (pointchecker[currentpoint + 1] == false) {
				pointchecker[currentpoint + 1] = true;
				spendingtime[currentpoint + 1] = spendingtime[currentpoint] + 1;
				footpoint[currentpoint + 1] = currentpoint;
				qu.push(currentpoint + 1);
			}			
		}
		if (currentpoint - 1 >= 0) {
			if (pointchecker[currentpoint - 1] == false) {
				pointchecker[currentpoint - 1] = true;
				spendingtime[currentpoint - 1] = spendingtime[currentpoint] + 1;
				footpoint[currentpoint - 1] = currentpoint;
				qu.push(currentpoint - 1);
			}
		}
		if (spendingtime[K] > 0)
			break;
	}
	std::cout << spendingtime[K] << std::endl;

	std::stack<int> printfoot;
	for (int i = K; i != N; ) {
		printfoot.push(i);
		i = footpoint[i];
	}
	printfoot.push(N);
	while (!printfoot.empty()) {
		std::cout << printfoot.top() << ' ';
		printfoot.pop();
	}

	return 0;
}