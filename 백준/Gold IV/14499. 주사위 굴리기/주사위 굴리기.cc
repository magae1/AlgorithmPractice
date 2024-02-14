/*
 14499 - 주사위 굴리기
 */
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 20;
const int MAX_M = 20;
const int MAX_NUM_OF_DIRECTIONS = 4;
enum moveDirection {
    EAST = 1,
    WEST = 2,
    NORTH = 3,
    SOUTH = 4
};

int map[MAX_N][MAX_M];

struct diceFace {
    int number;
    diceFace* facePtr[MAX_NUM_OF_DIRECTIONS+1];
};
diceFace dice[6];

bool isIllegalMovement(pair<int, int> position, moveDirection direction, int N, int M) {
    switch(direction) {
        case EAST:
            if (++position.second < M)
                return true;
            break;
        case WEST:
            if (--position.second >= 0)
                return true;
            break;
        case NORTH:
            if (--position.first >= 0)
                return true;
            break;
        case SOUTH:
            if (++position.first < N)
                return true;
            break;
    }
    return false;
}
pair<int,int> getNextPosition(pair<int, int> position, moveDirection direction) {
    int x = position.first, y = position.second;
    switch(direction) {
        case EAST:
            y++;
            break;
        case WEST:
            y--;
            break;
        case NORTH:
            x--;
            break;
        case SOUTH:
            x++;
            break;
    }
    return { x, y };
}
void initDice() {
    for (int i = 0; i < 6; i++) {
        dice[i].number = 0;
        if (i == 0) {
            dice[i].facePtr[NORTH] = &dice[1];
            dice[i].facePtr[SOUTH] = &dice[4];
            dice[i].facePtr[EAST] = &dice[2];
            dice[i].facePtr[WEST] = &dice[3];
        }
        else if (i == 1) {
            dice[i].facePtr[NORTH] = &dice[5];
            dice[i].facePtr[SOUTH] = &dice[0];
            dice[i].facePtr[EAST] = NULL;
            dice[i].facePtr[WEST] = NULL;
        }
        else if (i == 2) {
            dice[i].facePtr[NORTH] = NULL;
            dice[i].facePtr[SOUTH] = NULL;
            dice[i].facePtr[EAST] = &dice[5];
            dice[i].facePtr[WEST] = &dice[0];
        }
        else if (i == 3) {
            dice[i].facePtr[NORTH] = NULL;
            dice[i].facePtr[SOUTH] = NULL;
            dice[i].facePtr[EAST] = &dice[0];
            dice[i].facePtr[WEST] = &dice[5];
        }
        else if (i == 4) {
            dice[i].facePtr[NORTH] = &dice[0];
            dice[i].facePtr[SOUTH] = &dice[5];
            dice[i].facePtr[EAST] = NULL;
            dice[i].facePtr[WEST] = NULL;
        }
        else if (i == 5) {
            dice[i].facePtr[NORTH] = &dice[4];
            dice[i].facePtr[SOUTH] = &dice[1];
            dice[i].facePtr[EAST] = &dice[3];
            dice[i].facePtr[WEST] = &dice[2];
        }
    }
    
}
void moveDice(moveDirection instruction) {
    switch(instruction) {
        case NORTH:
            instruction = SOUTH;
            break;
        case SOUTH:
            instruction = NORTH;
            break;
        case EAST:
            instruction = WEST;
            break;
        case WEST:
            instruction = EAST;
            break;
    }
    
    diceFace* currentFacePtr = &dice[0];
    int prevFaceNumber = dice[0].number;
    int currentFaceNumber = dice[0].number;
    for (int i = 0; i < 4; i++) {
        currentFacePtr = currentFacePtr->facePtr[instruction];
        currentFaceNumber = currentFacePtr->number;
        currentFacePtr->number = prevFaceNumber;
        prevFaceNumber = currentFaceNumber;
        
//        cout << i << endl;
//        printf("%2d\n", dice[1].number);
//        printf("%d%d%d\n", dice[3].number, dice[0].number, dice[2].number);
//        printf("%2d\n", dice[4].number);
//        printf("%2d\n", dice[5].number);
//        cout << endl;
    }
}

int main() {
    int N, M, K;
    pair<int, int> dicePosition;
    cin >> N >> M >> dicePosition.first >> dicePosition.second >> K;
    
    for (int i = 0; i < N; i++) {
        
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    
    vector<moveDirection> instructions;
    while(K--) {
        int input;
        cin >> input;
        instructions.push_back((moveDirection)input);
    }
    
    initDice();
    for (moveDirection direction : instructions) {
        if (isIllegalMovement(dicePosition, direction, N, M)) {
            dicePosition = getNextPosition(dicePosition, direction);
            moveDice(direction);
            
            if (map[dicePosition.first][dicePosition.second] == 0) {
                map[dicePosition.first][dicePosition.second] = dice[0].number;
            }
            else {
                dice[0].number = map[dicePosition.first][dicePosition.second];
                map[dicePosition.first][dicePosition.second] = 0;
            }
            
            cout << dice[5].number << endl;
        }
    }
    return 0;
}
