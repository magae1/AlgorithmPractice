#include <iostream>

using namespace std;

int room[50][50];

enum BlockState {
    Uncleaned = 0,
    Wall = 1,
    Cleaned = 2
};

enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

void RobotSpin(short* direction) {
    if (*direction == NORTH)
        *direction = WEST;
    else
        (*direction)--;
}
void RobotClean(pair<int, int> position) {
    room[position.first][position.second] = Cleaned;
}
bool CanRobotMove(pair<int, int> position, short direction) {
    switch(direction) {
        case NORTH:
            position.first--;
            break;
        case EAST:
            position.second++;
            break;
        case SOUTH:
            position.first++;
            break;
        case WEST:
            position.second--;
            break;
    }
    if (room[position.first][position.second] == Uncleaned)
        return true;
    else
        return false;
}
void RobotMove(pair<int, int> *position, short direction) {
    switch(direction) {
        case NORTH:
            position->first--;
            break;
        case EAST:
            position->second++;
            break;
        case SOUTH:
            position->first++;
            break;
        case WEST:
            position->second--;
            break;
    }
}
bool CanRobotBackward(pair<int, int> position, short direction) {
    for (int i = 0; i < 2; i++)
        RobotSpin(&direction);
    switch(direction) {
        case NORTH:
            position.first--;
            break;
        case EAST:
            position.second++;
            break;
        case SOUTH:
            position.first++;
            break;
        case WEST:
            position.second--;
            break;
    }
    if (room[position.first][position.second] == Wall) {
        return false;
    }
    return true;
}
void RobotBackward(pair<int, int> *position, short direction) {
    for (int i = 0; i < 2; i++)
        RobotSpin(&direction);
    switch(direction) {
        case NORTH:
            position->first--;
            break;
        case EAST:
            position->second++;
            break;
        case SOUTH:
            position->first++;
            break;
        case WEST:
            position->second--;
            break;
    }
}

int main() {
    int roomRow, roomCol;
    int RobotCleand = 1;
    pair<int, int> robotPos;
    short robotDirection;
    
    cin >> roomRow >> roomCol;
    cin >> robotPos.first >> robotPos.second >> robotDirection;
    
    for (int i = 0; i < roomRow; i++) {
        for (int j = 0; j < roomCol; j++) {
            cin >> room[i][j];
        }
    }
    
    while(1) {
        RobotClean(robotPos);
        int roboCheck;
        for (roboCheck = 0; roboCheck < 4; roboCheck++) {
            RobotSpin(&robotDirection);
            if (CanRobotMove(robotPos, robotDirection))
                break;
        }
        if (roboCheck >= 4) {
            if (CanRobotBackward(robotPos, robotDirection)) {
                RobotBackward(&robotPos, robotDirection);
            }
            else {
                break;
            }
        }
        else {
            RobotMove(&robotPos, robotDirection);
            RobotCleand++;
        }
    }
    
    cout << RobotCleand << endl;
    return 0;
}
