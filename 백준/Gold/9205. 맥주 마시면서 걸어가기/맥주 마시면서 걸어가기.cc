#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
typedef std::pair<int, int> position;
const int MAX_BEER_COUNT = 20;
const int MAX_DISTANCE = 50;

int getDistance(position start, position destination) {
    return abs(start.first - destination.first) + abs(start.second - destination.second);
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        position home;
        position festival;
        int n;
        cin >> n;
        vector<position> convenienceStore(n);
        vector<bool> convenienceFlag(n, false);
        cin >> home.first >> home.second;
        for (int i = 0; i < n; i++)
            cin >> convenienceStore[i].first >> convenienceStore[i].second;
        cin >> festival.first >> festival.second;
                
        bool isHappy = false;
        queue<position> qu;
        qu.push(home);
        while(!qu.empty()) {
            position curPosition = qu.front();
            if (getDistance(curPosition, festival) <= MAX_DISTANCE*MAX_BEER_COUNT) {
                isHappy = true;
                break;
            }
            for (int i = 0; i < n; i++) {
                if (convenienceFlag[i] == false &&
                    getDistance(convenienceStore[i], curPosition) <= MAX_DISTANCE*MAX_BEER_COUNT) {
                    convenienceFlag[i] = true;
                    qu.push(convenienceStore[i]);
                }
            }
            qu.pop();
        }
        
        if (isHappy)
            cout << "happy" << endl;
        else
            cout << "sad" << endl;
        
    }
    return 0;
}
