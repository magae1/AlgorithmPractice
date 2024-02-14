#include <iostream>

int pstack[100000];
int sstack[100000];
int pfront = 0;
int pback = 0;
int sfront = 0;
int sback = 0;

void ppop_back(int a) {
	pstack[pback] = a;
	pback++;
}
int push_front() {
	int result = pstack[pfront];
	pstack[pfront] = 0;
	sstack[sfront] = 0;
	pfront++;
	sfront++;
	return result;
}

void ppush_n_spop() {
	pstack[pback] = pstack[pfront];
	pstack[pfront] = 0;
	pback++;
	pfront++;
}
void spush_n_spop() {
	sstack[sback] = sstack[sfront];
	sstack[sfront] = 0;
	sback++;
	sfront++;
}

bool schecker() {
	int i = 1;
	while (sfront + i < sback) {
		if (sstack[sfront] < sstack[sfront + i])
			return false;
		i++;
	}
	return true;
}

void clear() {
	pfront = 0;
	pback = 0;
	sfront = 0;
	sback = 0;
}

int main() {
	int testcase;
	std::cin >> testcase;
	while (testcase--) {
		int N, M;
		std::cin >> N >> M;
		for (int i = 0; i < N; i++)
			ppop_back(i);
		for (sback = 0; sback < N; sback++) {
			std::cin >> sstack[sback];
		}
		int count = 0;
		while (1) {
			int buf = -1;
			if (schecker()) {
				buf = push_front();
				count++;
			}
			else {
				ppush_n_spop();
				spush_n_spop();
			}
			if (buf == M) 
				break;
		}
		std::cout << count << std::endl;
		clear();
	}
	return 0;
}