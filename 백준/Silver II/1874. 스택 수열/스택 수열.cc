#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

char ch[200001];

int main() {
	int N, A;
	int pnum = 1;
	int chnum = 0;
	stack<int> stk;
	cin >> N;
	for (int i = 0; i < N; i ++) {
		cin >> A;
		while (pnum <= N+1) {
			if (stk.empty()) {
				stk.push(pnum);
				pnum++;
				ch[chnum] = '+';
				chnum++;
			}
			else {
				if (stk.top() < A) {
					stk.push(pnum);
					pnum++;
					ch[chnum] = '+';
					chnum++;
				}
				else if (stk.top() == A) {
					stk.pop();
					ch[chnum] = '-';
					chnum++;
					break;
				}
				else if (stk.top() > A) {
					stk.pop();
					ch[chnum] = '-';
					chnum++;
				}
			}
		}
	}
	if (pnum > N + 1)
		cout << "NO" << endl;
	else {
		for (int i = 0; ch[i] > 0; i++)
			printf("%c\n", ch[i]);
	}	
	return 0;
}