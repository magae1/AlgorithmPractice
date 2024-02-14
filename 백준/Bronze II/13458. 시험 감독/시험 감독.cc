#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, B, C;
    long long result = 0;
    cin >> N;
    vector<int> candidate(N);
    for (int i = 0; i < N; i++)
        cin >> candidate[i];
    cin >> B >> C;
    while (N--) {
        int tmp_can = candidate[N] - B;
        if (tmp_can > 0) {
            if (tmp_can % C > 0)
                result += tmp_can / C + 1;
            else
                result += tmp_can / C;
        }
        result += 1;
    }
    cout << result << endl;
    return 0;
}
