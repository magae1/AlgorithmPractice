#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N;
	set<int> deck;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		deck.emplace(input);
	}

	cin >> M;
	vector<bool> flag(M);
	for (int i = 0; i < M; i++) {
		int input;
		cin >> input;
		auto deckIt = deck.find(input);
		if (deckIt != deck.end()) {
			flag[i] = true;
		}
		else {
			flag[i] = false;
		}
	}

	for (bool f : flag) {
		cout << f << ' ';
	}
	return 0;
}