#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

long long stk[1000001];

void func() {
	stk[1] = 1;
	stk[2] = 2;
	stk[3] = 4;
	for (long long i = 4; i <= 1000000; i++) {
		stk[i] = ((stk[i - 1] + stk[i - 2]) % 1000000009 + stk[i - 3]) % 1000000009;
	}
}

int main() {
	func();
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", stk[n]);
	}
	return 0;
}
