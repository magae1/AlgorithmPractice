//
//  MakeStars_20.cpp
//  BaekJun_practice
//
//  Created by caurental on 2022/01/15.
//

#include <iostream>
using namespace std;

char stars[100];

void Star_Space_Star(int num)
{
    for (int i = 1; i < 2*num; i++)
    {
        if ((i % 2) != 0)
            stars[i-1] = '*';
        else
            stars[i-1] = ' ';
    }
}

int main(void)
{
    int N;
    cin >> N;
    Star_Space_Star(N);
    for (int i = 1; i <= N; i++)
    {
        if (i % 2 == 0)
            cout << ' ';
        cout << stars << endl;
    }
    return 0;
}