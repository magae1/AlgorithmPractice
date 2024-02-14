#include <iostream>
using namespace std;

int main() {
	int dot[4][2];
	for (int i = 0; i < 3; i++)
		cin >> dot[i][0] >> dot[i][1];
	if (dot[0][0] == dot[1][0]) {
		dot[3][0] = dot[2][0];
		if (dot[0][1] == dot[2][1])
			dot[3][1] = dot[1][1];
		else if (dot[1][1] == dot[2][1])
			dot[3][1] = dot[0][1];
	}
	else if (dot[1][0] == dot[2][0]) {
		dot[3][0] = dot[0][0];
		if (dot[1][1] == dot[0][1])
			dot[3][1] = dot[2][1];
		else if (dot[2][1] == dot[0][1])
			dot[3][1] = dot[1][1];
	}
	else if (dot[2][0] == dot[0][0]) {
		dot[3][0] = dot[1][0];
		if (dot[2][1] == dot[1][1])
			dot[3][1] = dot[0][1];
		else if (dot[0][1] == dot[1][1])
			dot[3][1] = dot[2][1];
	}
	cout << dot[3][0] << ' ' << dot[3][1] << endl;
	return 0;
}