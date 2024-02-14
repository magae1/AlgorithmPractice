#include <iostream>
using namespace std;

int main(void)
{
    int m;
    int n;
    int result_sum = 0;
    int result_min = 0;
    bool frt_check = true;
    cin >> m;
    cin >> n;
    
    for (int i = 0; i * i <= n; i++)
    {
        if (i * i >= m)
        {
            result_sum += i * i;
            if (frt_check)
            {
                frt_check = false;
                result_min = i * i;
            }
        }
    }
    
    if (result_sum == 0)
        cout << "-1" << endl;
    else
    {
        cout << result_sum << endl << result_min << endl;
    }
    
    return 0;
}
