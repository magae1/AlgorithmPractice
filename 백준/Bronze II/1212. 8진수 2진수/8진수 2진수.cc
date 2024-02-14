#include <iostream>
#include <stack>
#include <string>

std::stack<int> binastack;
int main() {
	std::string str;
	char ch;
	ch = getchar();
	while (ch != '\n') {
		int num = ch - 48;
		for (int i = 0; i < 3; i++) {
			binastack.push(num % 2);
			num /= 2;
		}
		while (!binastack.empty()) {
			str.push_back(binastack.top() + 48);
			binastack.pop();
		}
		ch = getchar();
	}
	while ((str.front() == '0') && (str.size() > 1)) {
		str.erase(0, 1);
	}
	std::cout << str;
	return 0;
}