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
    int TestCase;
    cin >> TestCase;
    int * Scores = new int[TestCase];
    for (int i = 0; i < TestCase; i++)
    {
        int beta_scores[5];
        for (int j = 0; j < 5; j++)
            cin >> beta_scores[j];
        quickSort(beta_scores, 0, 4);
        if (beta_scores[3] - beta_scores[1] > 3)
            Scores[i] = -1;
        else
            Scores[i] = beta_scores[1] + beta_scores[2] + beta_scores[3];
    }
    for (int i = 0; i < TestCase; i++)
    {
        if (Scores[i] == -1)
            cout << "KIN" << endl;
        else
            cout << Scores[i] << endl;
    }
    return 0;
}
