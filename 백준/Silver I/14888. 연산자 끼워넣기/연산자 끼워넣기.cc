#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int operating(int a, int b, int op) {
    switch (op) {
        case 0:
            return a+b;
        case 1:
            return a-b;
        case 2:
            return a*b;
        default:
            if (a >= 0)
                return a / b;
            else {
                a = -a;
                int tmp = a / b;
                return -tmp;
            }
    }
}
void func(int index, int n, vector<int> opds, int* opts, int num, int* maxi, int* mini) {
    if (index == n) {
        if (*mini > num)
            *mini = num;
        if (*maxi < num)
            *maxi = num;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (opts[i] > 0) {
            opts[i]--;
            int tmp = operating(num, opds[index], i);
            func(index+1, n, opds, opts, tmp, maxi, mini);
            opts[i]++;
        }
    }
}

int main() {
    int N;
    int opts[4];
    cin >> N;
    vector<int> opds(N);
    for (int i = 0; i < N; i++)
        cin >> opds[i];
    for (int i = 0; i < 4; i++)
        cin >> opts[i];
    int mini = INT_MAX;
    int maxi = INT_MIN;
    func(1, N, opds, opts, opds[0], &maxi, &mini);
    cout << maxi << endl << mini << endl;
    return 0;
}
