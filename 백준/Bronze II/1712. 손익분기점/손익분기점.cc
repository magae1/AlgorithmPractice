#include <iostream>
using namespace std;

int main() {
	unsigned int a, b, c;
	int buf_bnf = 0;
	int BE_point = 0;
	cin >> a >> b >> c;

	buf_bnf = c - b;

	if (buf_bnf > 0) {
		BE_point = a / buf_bnf + 1;
		
		cout << BE_point << endl;
	}
	else {
		cout << "-1" << endl;
	}

	return 0;
}