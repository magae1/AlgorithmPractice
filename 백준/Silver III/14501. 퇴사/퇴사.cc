#include <iostream>
#include <vector>
using namespace std;

typedef struct {
    int time;
    int paid;
} consaltingtable;


int main() {
    consaltingtable tables[15];
    int N;

    cin >> N;
    vector<int> earnedMoney(N+1, 0);
    for (int i = 0; i < N; i++)
        cin >> tables[i].time >> tables[i].paid;
    
    for (int i = 1; i <= N; i++) {
        if (((i-1) + tables[i-1].time) <= N+1) {
            for (int j = (i-1) + tables[i-1].time; j<= N+1; j++) {
                earnedMoney[j] = (earnedMoney[j] > earnedMoney[i-1] + tables[i-1].paid ? earnedMoney[j] : earnedMoney[i-1] + tables[i-1].paid);
            }
        }
    }

    cout << earnedMoney[N] << endl;
    return 0;
}
