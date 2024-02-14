#include <iostream>
#include <stack>
using namespace std;

int main () {
    int N, X;
    cin >> N >> X;
    
    if ( N * 26 < X || N * 1 > X) {
        cout << '!' << endl;
        return 0;
    }
    
    stack<char> stk;
    while(N--) {
        if (X - N >= 26) {
            stk.push('A'+25);
            X -= 26;
        }
        else {
            stk.push('A'+(X-N)-1);
            X -= (X-N);
        }
    }
    
    string str;
    while(!stk.empty()) {
        str.push_back(stk.top());
        stk.pop();
    }
    cout << str << endl;
    
    return 0;
}
