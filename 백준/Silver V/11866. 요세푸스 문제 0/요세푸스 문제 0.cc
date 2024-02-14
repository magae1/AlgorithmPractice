#include <iostream>

int ystack[1000000];
int yfront = 0;
int yback = 0;
void pop(int i) {
	ystack[yback] = i;
	yback++;
}
void push_n_pop() {
	ystack[yback] = ystack[yfront];
	ystack[yfront] = 0;
	yback++;
	yfront++;
}
int push_front() {
	int result = ystack[yfront];
	ystack[yfront] = 0;
	yfront++;
	return result;
}

int main() {
	int N, K;
	std::cin >> N >> K;
	for (int i = 1; i <= N; i++)
		pop(i);
	std::cout << '<';
	while (yback - yfront > 1) {
		for (int i = 0; i < K - 1; i++)
			push_n_pop();
		std::cout << push_front() << ", ";
	}
	std::cout << ystack[yfront] << '>' << std::endl;
	return 0;
}