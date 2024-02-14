#include <iostream>

int stacks[1000001];
int sfront = 0;
int sback = 0;

void pop_back(int a) {
	stacks[sback] = a;
	sback++;
}
void push_front() {
	stacks[sfront] = 0;
	sfront++;
}
void push_n_pop() {
	stacks[sback] = stacks[sfront];
	stacks[sfront] = 0;
	sfront++;
	sback++;
}

int main() {
	int N;
	std::cin >> N;
	for (int i = 1; i <= N; i++)
		pop_back(i);
	while (sback - sfront > 1) {
		push_front();
		push_n_pop();
	}
	std::cout << stacks[sfront] << std::endl;
	return 0;
}