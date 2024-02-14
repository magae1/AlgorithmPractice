#include <iostream>
#include <string>
#include <stack>
int main() {
	std::string str;
	std::stack<char> stk;
	int count = 0;
	std::getline(std::cin, str);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			stk.push(str[i]);
		}
		else if (str[i] == ')') {
			stk.pop();
			if (str[i - 1] == '(')
				count += stk.size();
			else
				count += 1;
		}
	}
	std::cout << count;
	return 0;
}