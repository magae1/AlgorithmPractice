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
    int fst = 0;
    int sum = 0;
    int M;
    int N;
    cin >> M >> N;
    for (int i = M; i <= N; i++)
    {
        if (IsItPrimeNum(i))
        {
            if (fst == 0)
                fst = i;
            sum += i;
        }
    }
    if (fst == 0)
        cout << "-1" << endl;
    else
        cout << sum << endl << fst << endl;
    return 0;
}
