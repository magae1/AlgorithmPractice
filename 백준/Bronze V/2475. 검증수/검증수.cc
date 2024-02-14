//
//  Verification Number.cpp
//  BaekJun_practice
//
//  Created by caurental on 2022/01/18.
//

#include <iostream>
using namespace std;

int Exponentiation(int a)
{
    return a * a;
}

int main(void)
{
    int result = 0;
    int buf = 0;
    int num;
    for (int i = 0; i < 5; i++)
    {
        cin >> num;
        buf += Exponentiation(num);
    }
    result = buf % 10;
    cout << result << endl;
    return 0;
}
