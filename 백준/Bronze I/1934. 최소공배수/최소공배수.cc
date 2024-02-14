#include <iostream>

int lcm(int a, int b) {
    int upup = (a > b ? a : b);
    int buf_upup = 0;
    int i = 1;
    while (true) {
        buf_upup = upup * i;
        if (buf_upup % a == 0 && buf_upup % b == 0)
            break;
        i++;
    }
    return buf_upup;
}

int main(void)
{
    int T;
    std::cin >> T;
    while (T--) {
        int fst, sec;
        std::cin >> fst >> sec;
        std::cout << lcm(fst, sec) << std::endl;
    }
    return 0;
}
