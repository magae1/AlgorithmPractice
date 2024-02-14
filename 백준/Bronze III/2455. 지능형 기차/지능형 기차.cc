 //
//  Intelligence_Train.cpp
//  BaekJun_practice
//
//  Created by caurental on 2022/01/18.
//

#include <iostream>
using namespace std;

int num_in_train = 0;
void LeftInTrain(int in, int out)
{
    num_in_train = num_in_train + in - out;
}

int main(void)
{
    int biggest_num = 0;
    int in, out;
    for (int i = 0; i < 4; i++)
    {
        cin >> out >> in;
        LeftInTrain(in, out);
        if (num_in_train > biggest_num)
            biggest_num = num_in_train;
    }
    cout << biggest_num << endl;
    return 0;
}
