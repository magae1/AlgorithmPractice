#include <iostream>
#include <string>
using namespace std;

int main() {
	const int buf_num = 2;
	int plus_num;
	int result = 0;
	string str;
	cin >> str;
	int str_size = size(str);
	for (int i = 0; i < str_size; i++) {
		if (str[i] > 'V')
			plus_num = 8;
		else if (str[i] > 'S')
			plus_num = 7;
		else if (str[i] > 'O')
			plus_num = 6;
		else if (str[i] > 'L')
			plus_num = 5;
		else if (str[i] > 'I')
			plus_num = 4;
		else if (str[i] > 'F')
			plus_num = 3;
		else if (str[i] > 'C')
			plus_num = 2;
		else
			plus_num = 1;
		result += (buf_num + plus_num);
	}
	cout << result << endl;
	return 0;
}