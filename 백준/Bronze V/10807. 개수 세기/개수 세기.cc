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
    int V;
    int Count = 0;
    cin >> N;
    int * nums = new int[N];
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    cin >> V;
    
    for (int i = 0; i < N; i++)
    {
        if (nums[i] == V)
            Count++;
    }
    cout << Count << endl;
    return 0;
}
