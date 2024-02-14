//
//  HalloweenCandy.cpp
//  BaekJun_practice
//
//  Created by caurental on 2022/01/14.
//

#include <iostream>
using namespace std;

int main(void)
{
    int TableCase;
    int c, v;
    cin >> TableCase;
    int * Yours = new int[TableCase];
    int * Dads = new int[TableCase];
    for (int i = 0; i < TableCase; i++)
    {
        cin >> c >> v;
        Yours[i] = c / v;
        Dads[i] = c % v;
    }
    for (int i = 0; i < TableCase; i++)
        cout << "You get " << Yours[i] << " piece(s) and your dad gets " << Dads[i] << " piece(s)." << endl;
    return 0;
}
