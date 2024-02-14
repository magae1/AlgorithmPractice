#include <iostream>
#include <string>
using namespace std;

int stacks[20000];
int fronts = 9999;
int backs = 10000;

void push_front(int a) {
	stacks[fronts] = a;
	fronts--;
}
void push_back(int a) {
	stacks[backs] = a;
	backs++;
}
int pop_front() {
	int result = stacks[fronts + 1];
	if (result == 0)
		return -1;
	else {
		stacks[fronts + 1] = 0;
		fronts++;
		return result;
	}
}
int pop_back() {
	int result = stacks[backs - 1];
	if (result == 0)
		return -1;
	else {
		stacks[backs - 1] = 0;
		backs--;
		return result;
	}
}
int size() {
	return backs - fronts - 1;
}

int empty() {
	if (size() == 0)
		return 1;
	else
		return 0;
}
int front() {
	int result = stacks[fronts + 1];
	if (result == 0)
		return -1;
	else
		return result;
}
int back() {
	int result = stacks[backs - 1];
	if (result == 0)
		return -1;
	else
		return result;
}

int main() {
	int N;
	cin >> N;
	while (N--) {
		string str;
		cin >> str;
		if (str == "push_back") {
			int i;
			cin >> i;
			push_back(i);
		}
		else if (str == "push_front") {
			int i;
			cin >> i;
			push_front(i);
		}
		else if (str == "pop_front") {
			cout << pop_front() << endl;
		}
		else if (str == "pop_back") {
			cout << pop_back() << endl;
		}
		else if (str == "size") {
			cout << size() << endl;
		}
		else if (str == "empty") {
			cout << empty() << endl;
		}
		else if (str == "front") {
			cout << front() << endl;
		}
		else if (str == "back") {
			cout << back() << endl;
		}
		else {
		}
	}
	return 0;
}