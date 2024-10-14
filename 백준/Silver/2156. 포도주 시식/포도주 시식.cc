#include <iostream>
#include <vector>

using namespace std;

const int MAX_CONTINUES_COUNT = 3;

int main() {
    int n;
    cin >> n;

    vector<int> cups(n);
    vector<vector<int> > drinks(n, vector<int>(MAX_CONTINUES_COUNT, 0));
    for (int i = 0; i < n; i++) {
        cin >> cups[i];
    }
    
    drinks[0][1] = cups[0];
    drinks[0][2] = cups[0];
    for (int i = 1; i < n; i++) {
        int prev_max = 0;
        for (int j = 0; j < MAX_CONTINUES_COUNT; j++) {
            prev_max = max(prev_max, drinks[i - 1][j]);
        }
        drinks[i][0] = prev_max;
        drinks[i][1] = drinks[i - 1][0] + cups[i];
        drinks[i][2] = drinks[i - 1][1] + cups[i];
    }
    
    int result = 0;
    for (int i = 0; i < MAX_CONTINUES_COUNT; i++) {
        result = max(result, drinks[n - 1][i]);
    }
    
    cout << result << endl;
    return 0;

}