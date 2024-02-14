//
//  Factorial.cpp
//  BaekJun_practice
//
//  Created by caurental on 2022/01/15.
//

#include <iostream>
using namespace std;

int stock[12];

int Facto(int n)
{
    if (n < 2)
        return 1;
    else
    {
        if (stock[n] > 0)
            return stock[n];
        else
            return Facto(n-1) * n;
    }
}

int main(void)
{
    int N;
    cin >> N;
    cout << Facto(N) << endl;
    return 0;
}
