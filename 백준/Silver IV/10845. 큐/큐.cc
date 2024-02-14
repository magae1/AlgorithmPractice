#include <iostream>
#include <string>
int start = 0;
int last = 0;
int stk[10000];

void Push(int n) {
	stk[last] = n;
	last++;
}
int Pop() {
	if (last > start) {
		int tmp = stk[start];
		stk[start] = 0;
		start++;
		return tmp;
	}
	return -1;
}
int Size() {
	return last - start;
}
int Empty() {
	if (last == start)
		return 1;
	return 0;
}
int Front() {
	if (last - start == 0)
		return -1;
	return stk[start];
}
int Back() {
	if (last - start == 0)
		return -1;
	return stk[last - 1];
}
int main() {
	int N;
	std::cin >> N;
	while (N--) {
		std::string str;
		std::cin >> str;
		if (str == "push") {
			int A;
			std::cin >> A;
			Push(A);
		}
		else if (str == "pop")
			std::cout << Pop() << std::endl;
		else if (str == "size")
			std::cout << Size() << std::endl;
		else if (str == "empty")
			std::cout << Empty() << std::endl;
		else if (str == "front")
			std::cout << Front() << std::endl;
		else if (str == "back")
			std::cout << Back() << std::endl;
	}
	return 0;
}