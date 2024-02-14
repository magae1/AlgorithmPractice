//
//  SangSu.cpp
//  BaekJun_practice
//
//  Created by caurental on 2022/01/18.
//

#include <iostream>
using namespace std;

int tens(int a)
{
    int result = 1;
    for (int i = 1; i <= a; i++)
    {
        result *= 10;
    }
    return result;
}


int Reverse(int a)
{
    int buf[3];
    int nums[3];
    int result;
    for (int i = 0; i < 3; i++)
        buf[i] = a / tens(i);
    for (int i = 0; i < 3; i++)
    {
        if (i < 2)
            nums[i] = buf[i] - buf[i+1] * 10;
        else
            nums[i] = buf[i];
    }
    result = nums[0] * tens(2) + nums[1] * tens(1) + nums[2];
    return result;
}

int main(void)
{
    int nu[2];
    for (int i = 0; i < 2; i++)
    {
        cin >> nu[i];
        nu[i] = Reverse(nu[i]);
    }
    if (nu[0] > nu[1])
        cout << nu[0] << endl;
    else
        cout << nu[1] << endl;
    return 0;
}
