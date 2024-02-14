#include <iostream>
#include <string>
using namespace std;

int sumandreturn(char a, char b) {
	return a + b - 96;
}

int main() {
	string str_a;
	string str_b;
	string str_re;
	cin >> str_a >> str_b;
	int buf_sum;
	int buf = 0;
	while (1) {
		if (str_a.empty() && str_b.empty()) {
			break;
		}
		else if (str_a.empty()) {
			buf_sum = sumandreturn('0', str_b.back());
			str_b.pop_back();
		}
		else if (str_b.empty()) {
			buf_sum = sumandreturn(str_a.back(), '0');
			str_a.pop_back();
		}
		else {
			buf_sum = sumandreturn(str_a.back(), str_b.back());
			str_a.pop_back();
			str_b.pop_back();
		}
		buf_sum += buf;
		buf = buf_sum / 10;
		buf_sum = buf_sum % 10;
		str_re.insert(0, 1, (char)(buf_sum + 48));
	}	
	if (buf > 0) {
		str_re.insert(0, 1, (char)(buf + 48));
	}
	cout << str_re << endl;
	return 0;
}