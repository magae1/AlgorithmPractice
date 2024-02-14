//
//  Easy _Quiz.cpp
//  BaekJun_Practice_101
//
//  Created by caurental on 2022/01/19.
//

#include <iostream>
using namespace std;

int WhatIsA(int a)
{
    int i = 1;
    int BF = 0;
    while(1)
    {
        BF += i;
        i++;
        if (BF >= a)
            break;
    }
    return i-1;
}

int main(void)
{
    int A, B;
    int result = 0;
    cin >> A >> B;
    for (int i = A; i <= B; i++)
        result += WhatIsA(i);
    cout << result << endl;
    return 0;
}

