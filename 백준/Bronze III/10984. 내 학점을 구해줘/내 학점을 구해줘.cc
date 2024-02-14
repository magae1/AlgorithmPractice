#include <iostream>
using namespace std;

int main(void)
{
    int T;
    cin >> T;
    float * Total_Grade = new float [T];
    int * Total_Sub = new int [T];
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            int buf_sub;
            float buf_grade;
            cin >> buf_sub >> buf_grade;
            Total_Grade[i] += buf_sub * buf_grade;
            Total_Sub[i] += buf_sub;
        }
    }
    for (int i = 0; i < T; i++)
    {
        float result = Total_Grade[i] / Total_Sub[i];
        printf("%d %.1f\n", Total_Sub[i], result);
    }
    return 0;
}
