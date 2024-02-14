#include<iostream>
using namespace std;

int main() {
	size_t A, B, C;
	cin >> A >> B >> C;
	size_t sstack[32];
	sstack[0] = A % C;
	for (int i = 1; i < 32; i++)
		sstack[i] = ((sstack[i - 1] % C) * (sstack[i - 1] % C)) % C;
	size_t buf_b = B;
	size_t result = 1;
	int i = 0;
	while (buf_b > 0) {
		size_t sub = buf_b % 2;
		if (sub == 1)
			result = (result * sstack[i]) % C;
		buf_b = buf_b >> 1;
		i++;
	}
	cout << result << endl;
	return 0;
}