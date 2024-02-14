#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int result = 0;
	int str_len = (int)size(str);
	while (str_len--) {
	if (str_len > 0) {
		if (str[str_len] == '-') {
			if (str[str_len - 1] == 'c' || str[str_len - 1] == 'd')
				result -= 1;
		}
		else if (str[str_len] == 'j') {
			if (str[str_len - 1] == 'l' || str[str_len - 1] == 'n')
				result -= 1;
		}
		else if (str[str_len] == '=') {
			if (str[str_len - 1] == 'c' || str[str_len - 1] == 's')
				result -= 1;
			else if (str[str_len - 1] == 'z') {
				result -= 1;
				if (str_len > 1) {
					if (str[str_len - 2] == 'd')
						result -= 1;
				}
			}
		}
	}

		result += 1;
	}
	cout << result << endl;

	return 0;
}