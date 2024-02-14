#include <iostream>
using namespace std;

void Swap(int &a, int &b)
{
    int buf = a;
    a = b;
    b = buf;
}

int main(void)
{
    int nums[3];
    for (int i = 0; i < 3; i++)
        cin >> nums[i];
    if (nums[0] > nums[1])
        Swap(nums[0], nums[1]);
    if (nums[0] > nums[2])
        Swap(nums[0], nums[2]);
    if (nums[1] > nums[2])
        Swap(nums[1], nums[2]);
    for (int i = 0; i < 3; i++)
        cout << nums[i] << ' ';
    cout << endl;
    return 0;
}
