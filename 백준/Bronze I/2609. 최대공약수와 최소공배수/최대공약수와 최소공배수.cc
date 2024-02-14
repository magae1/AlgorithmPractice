#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int gcd, int a, int b)
{
    int i = 1;
    int buf;
    while (1)
    {
        buf = gcd * i;
        int suf_1 = buf % a;
        int suf_2 = buf % b;
        if (suf_1 == 0 && suf_2 == 0)
            break;
        i++;
    }
    return (gcd * i);
}

int main(void)
{
    int fst, sec;
    int N_gcd, N_lcm;
    cin >> fst >> sec;
    N_gcd = gcd(fst, sec);
    N_lcm = lcm(N_gcd, fst, sec);
    cout << N_gcd << endl << N_lcm << endl;
    return 0;
}
