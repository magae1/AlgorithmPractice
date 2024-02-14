#include <iostream>
#include <cstring>
using namespace std;

int qt(const void* a, const void* b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    int T;
    cin >> T;
    int * Smallest = new int[T];
    int * Sums = new int[T];
    for (int i = 0; i < T; i++)
    {
        int nums[7];
        for (int j = 0; j < 7; j++)
            cin >> nums[j];
        qsort(nums, 7, sizeof(int), qt);
        for (int k = 0; k < 7; k++)
        {
            if (nums[k] % 2 == 0)
            {
                Sums[i] += nums[k];
                if (Smallest[i] == 0)
                    Smallest[i] = nums[k];
            }
        }
    }
    for (int i = 0; i < T; i++)
        cout << Sums[i] << ' ' << Smallest[i] << endl;
    return 0;
}
