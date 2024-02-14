//
//  Dice.cpp
//  BaekJun_practice
//
//  Created by caurental on 2022/01/14.
//

#include <iostream>
using namespace std;

int main(void)
{
    int TableCase;
    int frt, sec;
    cin >> TableCase;
    int * sum = new int[TableCase];
    for (int i = 0; i < TableCase; i++)
    {
        cin >> frt >> sec;
        sum[i] = frt + sec;
    }
    for (int i = 0; i < TableCase; i++)
    {
        cout << "Case " << i+1 << ": " << sum[i] << endl;
    }
    return 0;
}
