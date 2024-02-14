#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    int p;
    cin >> n;
    while(n--){
        int prize_own = 0;
        string name_onw;
        int prize_new = 0;
        string name_new;
        cin >> p;
        for (int i = 0; i < p; i++){
            cin >> prize_new >> name_new;
            if (prize_own < prize_new){
                name_onw = name_new;
                prize_own = prize_new;
            }
        }
        cout << name_onw << endl;
    }
    return 0;
}
