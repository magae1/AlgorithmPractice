/*
 14891 - 톱니바퀴
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

const char N_POLE = '0';
const char S_POLE = '1';
const int NUM_OF_TOUTHS = 8; //0 ~ 7
const int NUM_OF_GEARS = 4;
const int CLOCKWISE = 1;
const int ANTI_CLOCKWISE = -1;

enum position {
    LEFT, RIGHT
};

struct gear {
    int topToothIndex;
    char toothStatus[NUM_OF_TOUTHS+1];
};

gear gearsInfo[NUM_OF_GEARS];

char getGearPole(int gearIndex, position position) {
    int toothIndex = gearsInfo[gearIndex].topToothIndex;
    switch(position) {
        case LEFT:
            toothIndex = toothIndex-2 >= 0 ? toothIndex-2 : NUM_OF_TOUTHS + (toothIndex-2);
            break;
        case RIGHT:
            toothIndex = (toothIndex+2) % NUM_OF_TOUTHS;
            break;
        default:
            cout << "Wrong access!" << endl;
            exit(1);
    }
    return gearsInfo[gearIndex].toothStatus[toothIndex];
}
void moveGear(int gearIndex, int direction) {
    switch(direction) {
        case CLOCKWISE:
            gearsInfo[gearIndex].topToothIndex = gearsInfo[gearIndex].topToothIndex - 1 >= 0
            ? gearsInfo[gearIndex].topToothIndex - 1
            : NUM_OF_TOUTHS - 1;
            break;
        case ANTI_CLOCKWISE:
            gearsInfo[gearIndex].topToothIndex =  (gearsInfo[gearIndex].topToothIndex + 1) % NUM_OF_TOUTHS;
            break;
    }
}

int main() {
    for (int i = 0; i < NUM_OF_GEARS; i++) {
        gearsInfo[i].topToothIndex = 0;
        cin >> gearsInfo[i].toothStatus;
    }
    
    int K;
    cin >> K;
    vector<pair<int, int>> movements(K);
    for (int i = 0; i < K; i++) {
        cin >> movements[i].first >> movements[i].second;
    }
        
    for (auto movement : movements) {
//        입력된 톱니바퀴의 번호는 1~4번이지만, 이 코드에서 톱니바퀴의 번호는 0~3번이다.
        movement.first = movement.first -1;
        
        char leftToothPole = getGearPole(movement.first, LEFT);
        char rightToothPole = getGearPole(movement.first, RIGHT);
//        입력된 정보에 따른 톱니바퀴 회전.
        moveGear(movement.first, movement.second);
        bool isLeftGearMoved = true, isRightGearMoved = true;
        int nextDirection = -movement.second;
        
        for (int i = 1; i < NUM_OF_GEARS; i++) {
//            처음으로 움직인 톱니바퀴에서 왼쪽에 있는 톱니바퀴들에 대해 회전여부를 확인하고 회전한다.
            if (movement.first-i >= 0) {
                if (isLeftGearMoved && (leftToothPole != getGearPole(movement.first-i, RIGHT))) {
                    leftToothPole = getGearPole(movement.first-i, LEFT);
                    moveGear(movement.first-i, nextDirection);
                }
                else {
                    isLeftGearMoved = false;
                }
            }
//            처음으로 움직인 톱니바퀴에서 오른쪽에 있는 톱니바퀴들에 대해 회전여부를 확인하고 회전한다.
            if (movement.first+i < NUM_OF_GEARS) {
                if (isRightGearMoved && (rightToothPole != getGearPole(movement.first+i, LEFT))) {
                    rightToothPole = getGearPole(movement.first+i, RIGHT);
                    moveGear(movement.first+i, nextDirection);
                }
                else {
                    isRightGearMoved = false;
                }
            }
            nextDirection = -nextDirection;
        }
    }
    
    int result = 0;
    for (int i = 0; i < NUM_OF_GEARS; i++) {
        int topIndex = gearsInfo[i].topToothIndex;
        result += gearsInfo[i].toothStatus[topIndex] == S_POLE ? (int)exp2(i) : 0;
    }
    
    cout << result << endl;
    return 0;
}
