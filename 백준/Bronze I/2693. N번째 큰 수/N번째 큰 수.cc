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
    int * ThirdNums = new int[TestCase];
    for (int i = 0; i < TestCase; i++)
    {
        int beta[10];
        for (int j = 0; j < 10; j++)
            cin >> beta[j];
        qsort(beta, 10, sizeof(int), cmpfunc);
        ThirdNums[i] = beta[7];
    }
    for (int i = 0; i < TestCase; i++)
        cout << ThirdNums[i] << endl;
    return 0;
}
