#include <iostream>
using namespace std;

int main(void)
{
    int TestCase;
    cin >> TestCase;
    
    for (int i = 0; i < TestCase; i++)
    {
        int CarPrize;
        cin >> CarPrize;
        int NumOfOp;
        cin >> NumOfOp;
        int TotalPrize = 0;
        for (int j = 0; j < NumOfOp; j++)
        {
            int buf_Num;
            int buf_Prz;
            cin >> buf_Num >> buf_Prz;
            TotalPrize += (buf_Num * buf_Prz);
        }
        TotalPrize += CarPrize;
        cout << TotalPrize << endl;
    }
    return 0;
}
