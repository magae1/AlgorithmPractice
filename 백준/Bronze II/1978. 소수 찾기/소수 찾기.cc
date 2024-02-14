//
//  PrimeNumber.cpp
//  BaekJun_practice
//
//  Created by caurental on 2022/01/17.
//

#include <iostream>
using namespace std;

bool IsItPrimeNum(int n)
{
    if (n == 1)
        return false;
    int i = 2;
    while(i < n)
    {
        if (n % i == 0)
            return false;
        i++;
    }
    return true;
}

int main(void)
{
    int a;
    int num = 0;
    cin >> a;
    int input;
    for (int i = 0; i < a; i++)
    {
        cin >> input;
        if (IsItPrimeNum(input))
            num++;
    }
    cout << num << endl;
    return 0;
}
