#include <iostream>
using namespace std;

void Swap(int &a, int &b)
{
    int buf = a;
    a = b;
    b = buf;
}
void quickSort(int arr[], int L, int R)
{
    int left = L, right = R;
    int pivot = arr[(L+R) / 2];
    do
    {
        while(arr[left] < pivot)
            left++;
        while(pivot < arr[right])
            right--;
        if (left <= right)
        {
            Swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }while(left <= right);
    if (L < right)
        quickSort(arr, L, right);
    if (left < R)
        quickSort(arr, left, R);
}

int main(void)
{
    int nn[5];
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> nn[i];
        sum += nn[i];
    }
    quickSort(nn, 0, 4);
    cout << sum / 5 << endl << nn[2] << endl;
}
