#include <iostream>
#include <string>

int main(void) {
	int N;
	bool alphachecker[26];
	std::cin >> N;
	int result = N;

	while (N--) {
		for (int i = 0; i < 26; i++)
			alphachecker[i] = false;
		std::string str;
		std::cin >> str;
		int str_size = (int)str.size();
		for (int i = 0; i < str_size; i++) {
			if (alphachecker[(int)str[i] - 97]) {
				if (str[i - 1] != str[i]) {
					result -= 1;
					break;
				}
			}
			else 
				alphachecker[(int)str[i] - 97] = true;
		}
	}

	std::cout << result << std::endl;
	return 0;
}