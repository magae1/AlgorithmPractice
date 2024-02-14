#include <iostream>
#include <string>
#include <stack>
std::string expr;
std::string result;
std::stack<char> operatorstack;

namespace Branket {
	const int OpenBranket = 1;
	const int CloseBranket = -1;
}
int WhatParentheses(char c) {
	if (c == '(')
		return Branket::OpenBranket;
	else
		return Branket::CloseBranket;
}
bool IsParentheses(char c) {
	if (c == '(' || c == ')')
		return true;
	else
		return false;
}
bool IsOperand(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
}
bool IsAlpha(char c) {
	if (c >= 'A' && c <= 'Z')
		return true;
	else
		return false;
}
void PushOpRemains() {
	while (!operatorstack.empty()) {
		if (IsOperand(operatorstack.top())) {
			result.push_back(operatorstack.top());
		}		
		operatorstack.pop();
	}
}

void OpToptoRes() {
	while (!operatorstack.empty()) {
		if (operatorstack.top() == '*' || operatorstack.top() == '/') {
			result.push_back(operatorstack.top());
			operatorstack.pop();
		}
		else
			break;
	}
}
void OpToptoRes2() {
	while (!operatorstack.empty()) {
		if (IsOperand(operatorstack.top())) {
			result.push_back(operatorstack.top());
			operatorstack.pop();
		}
		else
			break;
	}
}

int main() {
	std::cin >> expr;
	int str_end = expr.size();	
	for (int i = 0; i < str_end; i++) {
		if (IsAlpha(expr[i])) {
			result.push_back(expr[i]);
			OpToptoRes();
		}
		else if (IsParentheses(expr[i])) {
			if (WhatParentheses(expr[i]) == Branket::OpenBranket) {
				operatorstack.push(expr[i]);
			}
			else if (WhatParentheses(expr[i]) == Branket::CloseBranket) {
				while (operatorstack.top() != '(') {
					if (IsOperand(operatorstack.top()))
						result.push_back(operatorstack.top());
					operatorstack.pop();
				}
				operatorstack.pop();
			}
		}
		else if (IsOperand(expr[i])) {
			if (expr[i] == '+' || expr[i] == '-')
				OpToptoRes2();
			else
				OpToptoRes();
			operatorstack.push(expr[i]);
		}		
	}
	PushOpRemains();
	std::cout << result;
	return 0;
}