#include <iostream>

int main() {
    int two_count = 0;
    int five_count = 0;
    int N;
    std::cin >> N;
    while(N > 1) {
        int buf_N = N;
        
        while(buf_N % 5 == 0) {
            buf_N = buf_N / 5;
            five_count++;
        }
        while(buf_N % 2 == 0) {
            buf_N = buf_N / 2;
            two_count++;
        }
        N--;
    }
    std::cout << (two_count < five_count ? two_count : five_count) << std::endl;
    return 0;
}
