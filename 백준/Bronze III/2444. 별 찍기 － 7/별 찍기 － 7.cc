#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < n - i - 1)
                cout << ' ';
            else
                cout << '*';
        }
        for (int j = 0; j < n; j++)
        {
            if (j < i)
                cout << '*';
        }
        cout << endl;
    }
    n--;
    for (int i = 0; i < n; i++)
    {
        cout << ' ';
        for (int j = 0; j < n; j++)
        {
            if (i > j)
                cout << ' ';
            else
                cout << '*';
        }
        for (int j = 0; j < n - i - 1; j++)
            cout << '*';
        cout << endl;
    }
    return 0;
}
