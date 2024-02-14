//
//  IAM_A_COOK.cpp
//  BaekJun_Practice_101
//
//  Created by caurental on 2022/01/18.
//

#include <iostream>
using namespace std;

int Biggest_Score(int * num, int size)
{
    int result = 0;
    int buf = 0;
    for (int i = 0; i < size; i++)
    {
        if (buf != 0)
        {
            if (num[i] > buf)
            {
                buf = num[i];
                result = i + 1;
            }
        }
        else
        {
            buf = num[i];
            result = i + 1;
        }
    }
    return result;
}

int main(void)
{
    int nums[] = {0, 0, 0, 0, 0};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int v;
            cin >> v;
            nums[i] += v;
        }
    }
    int re = Biggest_Score(nums, sizeof(nums)/sizeof(int));
    cout << re << endl << nums[re-1] << endl;
    return 0;
}
