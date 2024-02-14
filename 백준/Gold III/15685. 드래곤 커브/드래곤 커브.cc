#include <iostream>
#include <stack>
#include <deque>
using namespace std;
typedef pair<short, short> position;

const short MAX_XPOS = 100, MAX_YPOS = 100;
const short X_Up = 0;
const short Y_DOWN = 1;
const short X_DOWN = 2;
const short Y_UP = 3;
bool coordinate[MAX_XPOS+1][MAX_YPOS+1];

void moveNextPosition (position* position, short direction) {
    switch(direction) {
        case X_Up:
            position->first++;
            return;
        case Y_DOWN:
            position->second--;
            break;
        case X_DOWN:
            position->first--;
            break;
        case Y_UP:
            position->second++;
            break;
    }
}
void checkCoord(position position) {
    coordinate[position.first][position.second] = true;
}

int main() {
    int N;
    cin >> N;
    while(N--) {
        short x, y, d, g;
        cin >> x >> y >> d >> g;
        deque<short> frontDQ;
        deque<short> backDQ;
        stack<short> backupStk;
        frontDQ.push_front(d);
        while(g--) {
            while(!frontDQ.empty()) {
                backupStk.push(frontDQ.back());
                auto topIndex = (frontDQ.back()+ 1)%4;
                backDQ.push_back(topIndex);
                frontDQ.pop_back();
            }
            while(!backupStk.empty()) {
                frontDQ.push_back(backupStk.top());
                backupStk.pop();
            }
            while(!backDQ.empty()) {
                frontDQ.push_back(backDQ.front());
                backDQ.pop_front();
            }
        }
        
        position fstPosition = {x, y};
        checkCoord(fstPosition);
        while(!frontDQ.empty()) {
            moveNextPosition(&fstPosition, frontDQ.front());
            checkCoord(fstPosition);
            frontDQ.pop_front();
        }
    }
    
    int result = 0;
    for (int i = 0; i < MAX_XPOS; i++) {
        for (int j = 0; j < MAX_YPOS; j++) {
            if (coordinate[i][j] && coordinate[i+1][j] && coordinate[i][j+1] && coordinate[i+1][j+1])
                result++;
        }
    }
    cout << result << endl;
    return 0;
}
