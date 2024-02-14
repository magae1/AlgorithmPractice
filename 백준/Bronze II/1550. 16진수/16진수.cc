#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int hexa_to_demi(char ch) {
	int result = 0;
	if (ch >= 65 && ch <= 70)
		result = (int)ch - 55;
	else if (ch >= 48 && ch <= 57)
		result = (int)ch - 48;
	return result;
}

int main(void) {
	char ch[7];
	int output = 0;
	cin >> ch;
	int ch_len = strlen(ch);
	for (int i = 0; i < ch_len; i++)
		output += hexa_to_demi(ch[i]) * (int)pow(16, ch_len - i - 1);
	cout << output << endl;
	return 0;
}