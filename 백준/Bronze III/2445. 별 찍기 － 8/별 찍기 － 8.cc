#include <iostream>
using namespace std;

void CountingStars(int n, int index)
{
    for (int i = 1; i <= n; i++)
    {
        if (i > index)
            cout << ' ';
        else
            cout << '*';
    }
    for (int i = 1; i <= n; i++)
    {
        if (i > n - index)
            cout << '*';
        else
            cout << ' ';
    }
    cout << endl;
}

int main(void)
{
    int N;
    int index = 1;
    bool Max = true;
    cin >> N;
    if (N == 1)
        CountingStars(1, 1);
    else
    {
        while(1)
        {
            if (index == 0)
                break;
            CountingStars(N, index);
            if (Max)
            {
                index++;
                if (index == N)
                    Max = false;
            }
            else
                index--;
        }
    }
    return 0;
}
