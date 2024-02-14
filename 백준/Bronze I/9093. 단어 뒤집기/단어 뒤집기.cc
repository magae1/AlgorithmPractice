#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	int T;
	std::cin >> T;
	cin.ignore();
	while (T--) {
		string source, result;
		stack<char> stk;
		getline(cin, source);
		for (int i = 0; i < source.size(); i++) {
			if (source[i] == ' ') {
				while (!stk.empty()) {
					result += stk.top();
					stk.pop();
				}
				result += ' ';
			}
			else {
				stk.push(source[i]);
			}
		}
		while (!stk.empty()) {
			result += stk.top();
			stk.pop();
		}
		cout << result << endl;
	}
	return 0;
}