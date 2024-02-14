#include <iostream>
using namespace std;
int fbo(int n) {
    if (n < 2)
        return n;
    else {
        return fbo(n-1) + fbo(n-2);
    }
}

int main(void) {
    int T;
    cin >> T;
    cout << fbo(T) << endl;
    return 0;
}
