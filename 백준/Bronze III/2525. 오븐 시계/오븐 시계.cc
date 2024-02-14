#include <iostream>
using namespace std;

int main() {
    int H, M, T;
    cin >> H >> M >> T;
    int min = (M + T) % 60;
    int buf_hour = H + (M + T) / 60;
    int real_hour = buf_hour % 24;
    cout << real_hour << ' ' << min << endl;
    return 0;
}
