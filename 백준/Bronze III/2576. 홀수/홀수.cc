//
//  OddNumber.cpp
//  BaekJun_practice
//
//  Created by caurental on 2022/01/18.
//

#include <iostream>
using namespace std;

bool IsItOdd(int n)
{
    if (n%2 == 0)
        return false;
    else
        return true;
}

int main(void)
{
    int nums[7];
    int sum = 0;
    int Smallest_Odd_Num = 0;
    for (int i = 0; i < 7; i++)
        cin >> nums[i];
    for (int i = 0; i < 7; i++){
        if (IsItOdd(nums[i]))
        {
            sum += nums[i];
            if (Smallest_Odd_Num > 0)
            {
                if (Smallest_Odd_Num > nums[i])
                    Smallest_Odd_Num = nums[i];
            }
            else
                Smallest_Odd_Num = nums[i];
        }
    }
    if (Smallest_Odd_Num == 0)
        cout << "-1" << endl;
    else
        cout << sum << endl << Smallest_Odd_Num << endl;
    return 0;
}
