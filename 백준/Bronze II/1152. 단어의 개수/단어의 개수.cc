#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	bool Isitword = false;
	int count = 0;
	string str;
	getline(cin, str);
	for (int i = 0; str[i]; i++) {
		if (Isitword) {
			if (str[i] == ' ') {
				Isitword = false;
			}
		}
		else {
			if (isalpha(str[i])) {
				count++;
				Isitword = true;
			}
		}
	}
	cout << count << endl;
	return 0;
}