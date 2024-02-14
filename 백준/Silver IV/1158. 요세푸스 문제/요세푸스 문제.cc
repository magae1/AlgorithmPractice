#include <iostream>
#include <queue>

int main() {
	int N, K;
	std::cin >> N >> K;
	std::queue<int> qu;
	for (int i = 1; i <= N; i++)
		qu.push(i);

	std::cout << '<';
	while (qu.size() > 1) {
		for (int i = 0; i < K - 1; i++) {
			qu.push(qu.front());
			qu.pop();
		}
		std::cout << qu.front() << ", ";
		qu.pop();
	}
	std::cout << qu.front() << '>';
	return 0;
}