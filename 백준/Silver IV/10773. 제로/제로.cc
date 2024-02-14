#include <iostream>
#include <cstdlib>
using namespace std;

int stack[100000];
int topsize = 0;

void Push()
{
    stack[topsize] = 0;
    if (topsize > 0)
        topsize--;
}
void Pop(int a)
{
    stack[topsize] = a;
    topsize++;
}

int main(void)
{
    int K;
    cin >> K;
    int buf_input;
    for (int i = 0; i < K; i++)
    {
        cin >> buf_input;
        if (buf_input > 0)
            Pop(buf_input);
        else
            Push();
    }
    int result = 0;
    for (int i = 0; i < topsize; i++)
        result += stack[i];
    cout << result << endl;
    return 0;
}
