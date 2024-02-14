#include<iostream>
#include<string>
#include <stack>
#include <queue>
int main() {
	std::string str, result;
	std::stack<char> cham;
	std::queue<char> place;
	std::getline(std::cin, str);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '<') {
			if (!cham.empty()) {
				while (!cham.empty()) {
					result += cham.top();
					cham.pop();
				}
			}
			place.push(str[i]);
		}
		else if (str[i] == '>') {
			place.push(str[i]);
			while (!place.empty()) {
				result += place.front();
				place.pop();
			}
		}
		else if (str[i] == ' ') {
			if (place.empty()) {
				while (!cham.empty()) {
					result += cham.top();
					cham.pop();
				}
				result += str[i];
			}
			else
				place.push(str[i]);
		}
		else {
			if (place.empty())
				cham.push(str[i]);
			else
				place.push(str[i]);
		}
	}
	while (!cham.empty()) {
		result += cham.top();
		cham.pop();
	}
	std::cout << result;
	return 0;
}