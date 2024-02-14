#include <iostream>
#include <cstdlib>
using namespace std;

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(void)
{
    int TestCase;
    cin >> TestCase;
    int * results = new int[TestCase];
    for (int i = 0; i < TestCase; i++)
    {
        int Person;
        int seats;
        cin >> Person;
        cin >> seats;
        int * per_nums = new int [Person];
        for (int j = 0; j < Person; j++)
            cin >> per_nums[j];
        qsort(per_nums, Person, sizeof(int), cmpfunc);
        int buf_miss = 0;
        for (int k = 0; k < Person - 1; k++)
        {
            if (per_nums[k] == per_nums[k+1])
                buf_miss++;
        }
        results[i] = buf_miss;
    }
    for (int i = 0; i < TestCase; i++)
        cout << results[i] << endl;
    return 0;
}
