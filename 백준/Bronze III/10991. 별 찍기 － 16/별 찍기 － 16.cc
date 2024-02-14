//
//  MakeStars_16.cpp
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
        if (stars[i-1] == 0)
        {
            if ((i % 2) != 0)
                stars[i-1] = '*';
            else
                stars[i-1] = ' ';
        }
    }
}

int main(void)
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < (N - i); j++)
            cout << ' ';
        Star_Space_Star(i);
        
        cout << stars << endl;
    }
    return 0;
}
