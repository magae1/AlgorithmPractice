#include <iostream>
using namespace std;

void FrontStars(int n, int a)
{
    for (int i = 0; i < n; i++)
    {
        if (i < a)
            cout << ' ';
        else
            cout << '*';
    }
}
void BehindStars(int a)
{
    for (int i = 0; i < a; i++)
        cout << '*';
}

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        FrontStars(n,i);
        BehindStars((n - 1) - i);
        cout << endl;
    }
    for (int i = n - 1; i > 0; i--)
    {
        FrontStars(n,i-1);
        BehindStars(n - i);
        cout << endl;
    }
    return 0;
}
