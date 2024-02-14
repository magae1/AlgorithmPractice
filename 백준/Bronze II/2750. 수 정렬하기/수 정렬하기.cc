//
//  main.cpp
//  BaekJun_practice
//
//  Created by caurental on 2022/01/19.
//

#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int * nums_o = new int[N];
    int * nums_n = new int[N];
    int Min_num = 1000;
    for (int i = 0; i < N; i++)
    {
        cin >> nums_o[i];
        if (nums_o[i] < Min_num)
            Min_num = nums_o[i];
    }
    nums_n[0] = Min_num;
    for (int i = 0; i < N-1; i++)
    {
        Min_num = 1000;
        for (int j = 0; j < N; j++)
        {
            if (nums_o[j] > nums_n[i] && nums_o[j] < Min_num)
                Min_num = nums_o[j];
        }
        nums_n[i+1] = Min_num;
    }
    
    for (int i = 0; i < N; i++)
        cout << nums_n[i] << endl;
    return 0;
}
