//
//  10_rules.cpp
//  BaekJun_practice
//
//  Created by caurental on 2022/01/18.
//

#include <iostream>
using namespace std;

int main(void)
{
    int day;
    int car_num;
    int count = 0;
    cin >> day;
    for (int i = 0; i < 5; i++)
    {
        cin >> car_num;
        if (car_num == day)
            count++;
    }
    cout << count << endl;
    return 0;
}
