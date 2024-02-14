//
//  main.cpp
//  BaekJun_practice
//
//  Created by caurental on 2022/01/19.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    int scores[8];
    int sum = 0;
    bool checker[8];
    memset(checker,true,sizeof(bool) * 8);
    for (int i = 0; i < 8; i++)
        cin >> scores[i];
    for (int j = 0; j < 5; j++)
    {
        int Maxium = 0;
        int Max_index = 0;
        for (int i = 0; i < 8; i++)
        {
            if ((scores[i] > Maxium) && checker[i])
            {
                Maxium = scores[i];
                Max_index = i;
            }
        }
        sum += scores[Max_index];
        checker[Max_index] = false;
    }
    cout << sum << endl;
    for (int i = 0; i < 8; i++)
    {
        if(!(checker[i]))
            cout << i+1 << ' ';
    }
    cout << endl;
    return 0;
}
