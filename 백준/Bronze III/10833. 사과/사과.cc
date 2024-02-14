#include <iostream>
using namespace std;

int RemainApple(int student, int apple)
{
    return apple % student;
}

int main(void)
{
    int Sum = 0;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int buf_std, buf_app;
        cin >> buf_std >> buf_app;
        Sum += RemainApple(buf_std, buf_app);
    }
    cout << Sum << endl;
    return 0;
}
