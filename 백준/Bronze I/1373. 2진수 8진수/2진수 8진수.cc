#include <iostream>
#include <stack>
#include <cmath>

std::stack<char> inputstr;
std::stack<int> outnums;
int main() {
	char ch;
	ch = getchar();
	while (ch != '\n') {
		inputstr.push(ch);
		ch = getchar();
	}
	while (!inputstr.empty()) {
		int bufnum = 0;
		for (int i = 0; i < 3; i++) {
			if (inputstr.top() == '1')
				bufnum += static_cast<int>(pow(2, i));
			inputstr.pop();
			if (inputstr.empty())
				break;
		}
		outnums.push(bufnum);
	}
	while (!outnums.empty()) {
		std::cout << outnums.top();
		outnums.pop();
	}
	return 0;
}