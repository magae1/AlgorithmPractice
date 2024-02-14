//
//  Yutgame.cpp
//  BaekJun_practice
//
//  Created by caurental on 2022/01/18.
//

#include <iostream>
using namespace std;

char Yut_Checker(int n)
{
    if(n == 0)
        return 'E';
    else if(n == 1)
        return 'A';
    else if (n == 2)
        return 'B';
    else if (n == 3)
        return 'C';
    else
        return 'D';
}

int main(void)
{
    int yuts[3][4];
    char whatyut[3];
    for (int i = 0; i < 3; i++)
    {
        int buf = 0;
        for (int j = 0; j < 4; j++)
        {
            cin >> yuts[i][j];
            if (yuts[i][j] == 0)
                buf++;
        }
        whatyut[i] = Yut_Checker(buf);
    }
    for (int i = 0; i < 3; i++)
        cout << whatyut[i] << endl;
    
    return 0;
}
