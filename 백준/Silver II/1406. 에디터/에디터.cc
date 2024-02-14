#include<iostream>
#include <stack>
#include <string>
std::stack<char>leftonp;
std::stack<char>rightonp;

void Leftmove() {
	if (!leftonp.empty()) {
		rightonp.push(leftonp.top());
		leftonp.pop();		
	}
}
void Rightmove() {
	if (!rightonp.empty()) {
		leftonp.push(rightonp.top());
		rightonp.pop();
	}
}
void DeleteLeftone() {
	if (!leftonp.empty())
		leftonp.pop();
}
void Pushonleft(char ch) {
	leftonp.push(ch);
}
void Movelefttoright() {
	while (!leftonp.empty()) {
		rightonp.push(leftonp.top());
		leftonp.pop();
	}
}

int main() {
	std::string ch;
	std::cin >> ch;
	for (int i = 0; i < ch.size(); i++)
		leftonp.push(ch[i]);
	int N;
	std::cin >> N;
	while (N--) {
		char c;
		std::cin >> c;
		if (c == 'L')
			Leftmove();
		else if (c == 'D')
			Rightmove();
		else if (c == 'B')
			DeleteLeftone();
		else if (c == 'P') {
			char num;
			std::cin >> num;
			Pushonleft(num);
		}
	}
	Movelefttoright();
	while (!rightonp.empty()) {
		printf("%c", rightonp.top());
		rightonp.pop();
	}
	return 0;
}