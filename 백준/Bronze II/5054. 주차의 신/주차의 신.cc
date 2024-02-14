//
//  main.cpp
//  BaekJun_practice
//
//  Created by caurental on 2022/01/19.
//

#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{
    int TableCase;
    cin >> TableCase;
    int * Results = new int[TableCase];
    for (int i = 0; i < TableCase; i++)
    {
        int N;
        cin >> N;
        int Min_value = 99;
        int Max_value = 0;
        int buf;
        for (int j = 0; j < N; j++)
        {
            cin >> buf;
            if (buf > Max_value)
                Max_value = buf;
            if (buf < Min_value)
                Min_value = buf;
        }
        Results[i] = 2 * (Max_value - Min_value);
    }
    for (int i = 0; i < TableCase; i++)
        cout << Results[i] << endl;
    delete[] Results;
    return 0;
}
