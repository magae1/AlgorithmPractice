//
//  Score_Calculator.cpp
//  BaekJun_practice
//
//  Created by caurental on 2022/01/18.
//

#include <iostream>
using namespace std;

int main(void)
{
    int playtimes;
    cin >> playtimes;
    int TotalScore = 0;
    int buf_score = 0;
    int buf_grade;
    for (int i = 0; i < playtimes; i++)
    {
        cin >> buf_grade;
        if (buf_grade == 1)
            buf_score++;
        else
            buf_score = 0;
        TotalScore += buf_score;
    }
    cout << TotalScore << endl;
    return 0;
}
