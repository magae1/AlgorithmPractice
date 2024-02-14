#include <iostream>
using namespace std;

unsigned long buf[91];

unsigned long fibo(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
    {
        if (buf[n] > 0)
        {
            return buf[n];
        }
        buf[n] = fibo(n - 1) + fibo(n - 2);
        return buf[n];
    }
}

int main(void)
{
    int a;
    cin >> a;
    cout << fibo(a) << endl;
    return 0;
}
