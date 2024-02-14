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
    int pivot = arr[(L + R) / 2];
    do
      {
        while (arr[left] < pivot)
            left++;
        while (arr[right] > pivot)
            right--;
        if (left <= right)
        {
            Swap(arr[left],arr[right]);
            left++;
            right--;
        }
      } while (left <= right);
 
    if (L < right)
        quickSort(arr, L, right);
 
    if (left < R)
        quickSort(arr, left, R);
}

int main(void)
{
    int Hamburger[3];
    int Beverage[2];
    for (int i = 0; i < 5; i++)
    {
        if (i < 3)
            cin >> Hamburger[i];
        else
            cin >> Beverage[i-3];
    }
    quickSort(Hamburger, 0, 2);
    quickSort(Beverage, 0, 1);
    cout << Hamburger[0] + Beverage[0] - 50 << endl;
}