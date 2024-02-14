#include <iostream>
#include <string>
int main() {
    int casetest;
    std::cin >> casetest;
    while(casetest--){
        int n;
        std::cin >> n;
        std::string * strs = new std::string[n];
        std::string clothname;
        int * strstimes = new int[n];
        for (int i = 0; i < n; i++) {
            std::cin >> clothname >> strs[i];
            strstimes[i] = 1;
        }
        for (int i = 0; i < n - 1; i++) {
            int aftpos = i + 1;
            while (aftpos < n) {
                if (strstimes[i] > -1) {
                    if (strstimes[aftpos] > -1) {
                        if (strs[i] == strs[aftpos]) {
                            strstimes[aftpos] = -1;
                            strstimes[i] += 1;
                        }
                    }
                }
                aftpos++;
            }
        }
        int result = 1;
        for (int i = 0; i < n; i++) {
            if (strstimes[i] > 0) {
                result = result * (strstimes[i] + 1);
            }
        }
        std::cout << result - 1 << std::endl;
        delete[] strs;
        delete[] strstimes;
    }
    return 0;
}
