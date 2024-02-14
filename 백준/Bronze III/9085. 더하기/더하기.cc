//
//  Adder.cpp
//  BaekJun_practice
//
//  Created by caurental on 2022/01/18.
//

#include <iostream>
using namespace std;

int main(void)
{
    int T;
    int N;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        int result = 0;
        int buf_num;
        for (int j = 0; j < N; j++)
        {
            cin >> buf_num;
            result += buf_num;
        }
        cout << result << endl;
    }
    return 0;
}
