//
//  Find_Divisor.cpp
//  BaekJun_practice
//
//  Created by caurental on 2022/01/18.
//

#include <iostream>
using namespace std;

int divisor(int n, int k)
{
    int * nums = new int[n];
    int j = 0;
    if (k == 1)
    {
        delete []nums;
        return k;
    }
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            nums[j] = i;
            j++;
        }
    }
    if (nums[k-1] > 0)
    {
        delete []nums;
        return nums[k-1];
    }
    else
    {
        delete []nums;
        return 0;
    }
}

int main(void)
{
    int a, b;
    cin >> a >> b;
    cout << divisor(a, b) << endl;
    return 0;
}
