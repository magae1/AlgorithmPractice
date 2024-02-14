#include <iostream>
using namespace std;

size_t gcd(size_t fr, size_t to){
    while (to != 0) {
        size_t r = fr % to;
        fr = to;
        to = r;
    }
    return fr;
}
int main() {
    int N;
    cin >> N;
    size_t * radious = new size_t[N];
    for (int i = 0; i < N; i++)
        cin >> radious[i];
    for (int j = 1; j < N; j++) {
        size_t sub = gcd(radious[0], radious[j]);
        printf("%lu/%lu\n", radious[0] / sub, radious[j] / sub);
    }
    return 0;
}
