//
//  Domino.cpp
//  BaekJun_practice
//
//  Created by caurental on 2022/01/14.
//

#include <iostream>
using namespace std;

int stock[1000];

int CountDots(int n)
{
    if (n == 0)
        return 0;
    else{
        if (stock[n] == 0)
        {
            for (int i = n; i <= 2 * n; i++)
                stock[n] += i;
        }
        return CountDots(n-1) + stock[n];
    }
}

int main(void)
{
    int a;
    cin >> a;
    cout << CountDots(a) << endl;
    return 0;
}
