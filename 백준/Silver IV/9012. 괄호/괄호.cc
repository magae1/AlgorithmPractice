#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
    int testdata;
    cin >> testdata;
    while(testdata--) {
        char input[51];
        int stk_size = 0;
        cin >> input;
        for (int i = 0; i < strlen(input)+1; i++) {
            if (input[i] == '(')
                stk_size++;
            else if (input[i] == ')')
                stk_size--;
            if (stk_size < 0) {
                break;
            }
        }
        if (stk_size == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

