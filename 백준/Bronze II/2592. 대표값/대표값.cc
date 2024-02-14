//
//  RepresentativeValue.cpp
//  BaekJun_practice
//
//  Created by caurental on 2022/01/18.
//

#include <iostream>
using namespace std;

class MUN
{
private:
    int num[101];
public:
    MUN()
    {
        
    }
    void Intalize()
    {
        for (int i = 0; i < 101; i++)
            num[i] = 0;
    }
    void PutNum(int a)
    {
        num[a/10]++;
    }
    int ShowMUN()
    {
        int buf = 0;
        int result = 0;
        for (int i = 1; i <= 100; i++)
        {
            if (buf == 0)
            {
                buf = num[i];
                result = i;
            }
            else
            {
                if (num[i] > buf)
                {
                    buf = num[i];
                    result = i;
                }
            }
        }
        return result * 10;
    }
};

int main(void)
{
    int nums[10];
    int sum = 0;
    MUN mun;
    mun.Intalize();
    for (int i = 0; i < 10; i++)
    {
        cin >> nums[i];
        mun.PutNum(nums[i]);
        sum += nums[i];
    }
    cout << sum / 10 << endl << mun.ShowMUN() << endl;
    return 0;
}
