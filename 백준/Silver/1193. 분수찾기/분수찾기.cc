#include <iostream>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	int total_num = 2;
	int frt_num = 1;
	int back_num = 1;
	N--;
	while (N--) {
		if (total_num % 2 == 1) {
			if (back_num == 1) {
				total_num += 1;
				frt_num += 1;
			}
			else {
				frt_num += 1;
			}
		}
		else {
			if (frt_num == 1) {
				total_num += 1;
			}
			else {
				frt_num -= 1;
			}
		}
		back_num = total_num - frt_num;
	}
	printf("%d/%d\n", frt_num, back_num);
	return 0;
}