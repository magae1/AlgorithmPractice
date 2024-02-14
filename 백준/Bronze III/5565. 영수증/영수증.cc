#include <iostream>
#define NUM_OF_READABLE_BOOKS 9
using namespace std;

int main(void)
{
    int Total;
    int Readable;
    cin >> Total;
    for (int i = 0; i < NUM_OF_READABLE_BOOKS; i++)
    {
        cin >> Readable;
        Total -= Readable;
    }
    cout << Total << endl;
    return 0;
}
