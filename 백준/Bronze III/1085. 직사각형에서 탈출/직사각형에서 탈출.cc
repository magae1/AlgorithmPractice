#include <iostream>
using namespace std;

int min(int a, int b) {
	if (a <= b)
		return a;
	else if (a >= b)
		return b;
}

int main() {
	int x, y, w, h;
	int distance;
	cin >> x >> y >> w >> h;
	distance = min(min(min(x, y), w - x), h - y);
	cout << distance << endl;
	return 0;
}