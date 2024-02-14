#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int buf;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        result += buf;
    }
    cout << result - (n - 1) << endl;
    return 0;
}
