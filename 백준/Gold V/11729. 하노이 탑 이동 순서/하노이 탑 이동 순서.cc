#include <iostream>

int nn[20];
int toptop(int n) {
    if (n == 1)
        return n;
    else {
        if (nn[n] > 0) {
            return nn[n];
        }
        else {
            nn[n] = 2 * toptop(n-1) + 1;
            return nn[n];
        }
    }
}

void ff(int s, int d, int n) {
    if (n == 1) {
        printf("%d %d\n", s, d);
    }
    else {
        if (s == 1) {
            if (d == 2) {
                ff(1, 3, n-1);
                printf("%d %d\n", s, d);
                ff(3, 2, n-1);
            }
            else if (d == 3) {
                ff(1, 2, n-1);
                printf("%d %d\n", s, d);
                ff(2, 3, n-1);
            }
        }
        else if (s == 2) {
            if (d == 1) {
                ff(2, 3, n-1);
                printf("%d %d\n", s, d);
                ff(3, 1, n-1);
            }
            else if (d == 3) {
                ff(2, 1, n-1);
                printf("%d %d\n", s, d);
                ff(1, 3, n-1);
            }
        }
        else if (s == 3) {
            if (d == 1) {
                ff(3, 2, n-1);
                printf("%d %d\n", s, d);
                ff(2, 1, n-1);
            }
            else if (d == 2) {
                ff(3, 1, n-1);
                printf("%d %d\n", s, d);
                ff(1, 2, n-1);
            }
        }
    }
}

int main(void) {
    int N;
    scanf("%d", &N);
    printf("%d\n", toptop(N));
    ff(1, 3, N);
    return 0;
}
