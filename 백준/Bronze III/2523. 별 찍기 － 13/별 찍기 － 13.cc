#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << '*' << endl;
        return 0;
    }
    int i = 1;
    bool Max = true;
    while(i != 0)
    {
        for (int j = 0; j < i; j++)
            cout << '*';
        cout << endl;
        if (Max)
        {
            i++;
            if (i == n)
                Max = false;
        }
        else
        {
            i--;
        }
    }
    return 0;
}
