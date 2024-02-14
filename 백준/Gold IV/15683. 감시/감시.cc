/*
 15683 - 감시
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
typedef pair<int,int> position;

struct officeBlock {
    char origin;
    char temp;
};
const int MAX_N = 8;
const int MAX_M = 8;
const char MONITORED_AREA = '#';
const char WALL = '6';

officeBlock office[MAX_N][MAX_M];
void initOffice(int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            office[i][j].temp = office[i][j].origin;
        }
    }
}
void printOneDirectionForOrigin(position position, int N, int M, short direction) {
    while(1) {
        switch(direction) {
            case 0:
                position.first -= 1;
                break;
            case 1:
                position.second += 1;
                break;
            case 2:
                position.first += 1;
                break;
            case 3:
                position.second -= 1;
                break;
        }
        
        if (position.first >= 0 && position.first < N && position.second >= 0 && position.second < M &&
            office[position.first][position.second].origin != WALL) {
            if (office[position.first][position.second].origin == '0')
                office[position.first][position.second].origin = MONITORED_AREA;
        } else
            return;
    }
}
void printOneDirection(position position, int N, int M, short direction) {
    while(1) {
        switch(direction) {
            case 0:
                position.first -= 1;
                break;
            case 1:
                position.second += 1;
                break;
            case 2:
                position.first += 1;
                break;
            case 3:
                position.second -= 1;
                break;
        }
        
        if (position.first >= N || position.first < 0 || position.second >= M || position.second < 0 || office[position.first][position.second].origin == WALL) {
            return;
        }
        office[position.first][position.second].temp = MONITORED_AREA;
    }
}
short countUnmonitored(int N, int M) {
    short result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (office[i][j].temp == '0')
                result++;
        }
    }
    return result;
}
void fst(position position, int N, int M, short direction) {
    printOneDirection(position, N, M, direction);
}
void sec(position position, int N, int M, short direction) {
    short nextDirection = (direction + 2) % 4;
    printOneDirection(position, N, M, direction);
    printOneDirection(position, N, M, nextDirection);
}
void thr(position position, int N, int M, short direction) {
    short nextDirection = (direction + 1) % 4;
    printOneDirection(position, N, M, direction);
    printOneDirection(position, N, M, nextDirection);
}
void fur(position position, int N, int M, short direction) {
    short nextDirection = (direction + 1) % 4;
    short nextnextDirection = (direction + 2) % 4;
    printOneDirection(position, N, M, direction);
    printOneDirection(position, N, M, nextDirection);
    printOneDirection(position, N, M, nextnextDirection);
}

void monitorCCTV(position position, int N, int M, char camera, short direction) {
    switch(camera) {
        case '1':
            fst(position, N, M, direction);
            break;
        case '2':
            sec(position, N, M, direction);
            break;
        case '3':
            thr(position, N, M, direction);
            break;
        case '4':
            fur(position, N, M, direction);
            break;
    }
}

void func(int N, int M, vector<pair<char, position>>& camera, vector<short>& directions, int index, short* result) {
    if (camera.size() == index) {
        initOffice(N, M);
        for (int i = 0; i < index; i++) {
            monitorCCTV(camera[i].second, N, M, camera[i].first, directions[i]);
        }
        short count = countUnmonitored(N, M);
        *result = min(*result, count);
        return;
    }
    
    for (short i = 0; i < 4; i++) {
        directions[index] = i;
        func(N, M, camera, directions, index + 1, result);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<char, position>> cctvs;
    vector<position> fiveCCTVs;
    vector<short> direction;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char input;
            cin >> input;
            office[i][j].origin = input;
            if (input == '0' || input == WALL)
                continue;
            
            if (input == '5') {
                fiveCCTVs.push_back({i,j});
            }
            else {
                cctvs.push_back({input, {i, j}});
                direction.push_back(0);
            }
        }
    }
    for (position five : fiveCCTVs) {
        for (short direction = 0; direction < 4; direction++) {
            printOneDirectionForOrigin(five, N, M, direction);
        }
    }
    
    
    short result = SHRT_MAX;
    func(N, M, cctvs, direction, 0, &result);
    
    cout << result << endl;
    return 0;
}
