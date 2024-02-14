#include <iostream>
int main() {
    int testcase;
    std::cin >> testcase;
    while(testcase--){
        char ch[81];
        int n;
        std::cin >> n >> ch;
        for (int i = - 1; ch[i + n] > 0; i++){
            ch[i+n] = ch[i+n+1];
        }
        std::cout << ch << std::endl;
    }
    return 0;
}
