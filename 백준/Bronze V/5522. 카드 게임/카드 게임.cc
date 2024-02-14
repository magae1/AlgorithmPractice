#include <iostream>
using namespace std;

int main(void)
{
    int sum = 0;
    int buf;
    for (int i = 0; i < 5; i++)
    {
        cin >> buf;
        sum += buf;
    }
    cout << sum << endl;
    return 0;
}