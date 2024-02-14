#include <iostream>
using namespace std;

int main(void) {
    int N;
    int M;
    cin >> N >> M;
    int cards[100];
    for (int i = 0; i < N; i++)
        cin >> cards[i];
    int f = 0;
    int s = 1;
    int l = 2;
    int result = 0;
    int buf = 0;
    while(f <= N-3) {
        buf = cards[f] + cards[s] + cards[l];
        if (buf == M) {
            result = buf;
            break;
        }
        else if (result < buf && buf < M) {
            result = buf;
        }
        if (l >= N-1){
            if (s >= N-2) {
                f++;
                s = f+1;
                l = s+1;
            }
            else{
                s++;
                l = s+1;
            }
        }
        else {
            l++;
        }
    }
    cout << result << endl;
    return 0;
}
