//암호만들기
#include <iostream>

char ch[4];
static const int ALPHA_NUM = 26;

void func(int index, int start, int L, bool alpha[], bool checker[]) {
	if (index == L) {
		int moum = 0;
		int jaum = 0;
		for (int i = 0; i < L; i++) {
			if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u')
				moum++;
			else
				jaum++;
		}
		if (moum >= 1 && jaum >= 2) {
			for (int i = 0; i < L; i++)
				std::cout << ch[i];
			std::cout << std::endl;
		}
		return;
	}
	for (int i = start; i < ALPHA_NUM; i++) {
		if (checker[i] == true)
			continue;
		if (alpha[i] == true) {
			checker[i] = true;
			ch[index] = (char)(i + 97);
			func(index + 1, i, L, alpha, checker);
			checker[i] = false;
		}
	}
	return;
}

int main() {
	bool alpha[ALPHA_NUM];
	bool alpha_checker[ALPHA_NUM];
	for (int i = 0; i < ALPHA_NUM; i++) {
		alpha[i] = false;
		alpha_checker[i] = false;
	}		
	int L, C;
	std::cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char A;
		std::cin >> A;
		alpha[(int)A - 97] = true;
	}
	func(0, 0, L, alpha, alpha_checker);
	return 0;
} 