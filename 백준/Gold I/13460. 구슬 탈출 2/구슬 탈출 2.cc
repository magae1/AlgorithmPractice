/*
 13460 - 구슬 탈출 2
 */
#include <iostream>
#include <queue>
const int MAX_N = 10, MAX_M = 10;
enum boardState {
    RED_BEAD = 'R',
    BLUE_BEAD = 'B',
    HOLE = 'O',
    WALL = '#',
};
enum direction {
    EAST = 0,
    WEST = 1,
    SOUTH = 2,
    NORTH = 3
};

typedef std::pair<int, int> position;
const position HOLE_IN = { -1, -1 };
char board[MAX_N][MAX_M+1];

bool isBeadMovable(position checkBead, position otherBead, direction direction) {
    switch(direction) {
        case EAST:
            checkBead.second += 1;
            break;
        case WEST:
            checkBead.second -= 1;
            break;
        case SOUTH:
            checkBead.first += 1;
            break;
        case NORTH:
            checkBead.first -= 1;
            break;
    }
    if (checkBead == otherBead || board[checkBead.first][checkBead.second] == WALL) {
        return false;
    }
    else
        return true;
}
void getFstAndSecBead(position redBead, position blueBead, std::pair<char, position>* fstPositionPtr, std::pair<char, position>* secPositionPtr, direction direction) {
    switch(direction) {
        case EAST:
            if (redBead.second < blueBead.second) {
                *fstPositionPtr = { BLUE_BEAD, blueBead };
                *secPositionPtr = { RED_BEAD, redBead };
            }
            else {
                *fstPositionPtr = { RED_BEAD, redBead };
                *secPositionPtr = { BLUE_BEAD, blueBead };
            }
            break;
        case WEST:
            if (redBead.second > blueBead.second) {
                *fstPositionPtr = { BLUE_BEAD, blueBead };
                *secPositionPtr = { RED_BEAD, redBead };
            }
            else {
                *fstPositionPtr = { RED_BEAD, redBead };
                *secPositionPtr = { BLUE_BEAD, blueBead };
            }
            break;
        case SOUTH:
            if (redBead.first < blueBead.first) {
                *fstPositionPtr = { BLUE_BEAD, blueBead };
                *secPositionPtr = { RED_BEAD, redBead };
            }
            else {
                *fstPositionPtr = { RED_BEAD, redBead };
                *secPositionPtr = { BLUE_BEAD, blueBead };
            }
            break;
        case NORTH:
            if (redBead.first > blueBead.first) {
                *fstPositionPtr = { BLUE_BEAD, blueBead };
                *secPositionPtr = { RED_BEAD, redBead };
            }
            else {
                *fstPositionPtr = { RED_BEAD, redBead };
                *secPositionPtr = { BLUE_BEAD, blueBead };
            }
            break;
    }
}
void moveBead(position* movedBead, direction direction) {
    switch(direction) {
        case EAST:
            movedBead->second += 1;
            break;
        case WEST:
            movedBead->second -= 1;
            break;
        case SOUTH:
            movedBead->first += 1;
            break;
        case NORTH:
            movedBead->first -= 1;
            break;
    }
}

int main() {
    int N, M;
    std::cin >> N >> M;
    
    std::queue<position> redBeadQu, blueBeadQu;
    std::queue<int> moveCountQu;
    position holePosition;
    for (int i = 0; i < N; i++) {
        std::cin >> board[i];
        for (int j = 0; j < M; j++) {
            if (board[i][j] == RED_BEAD)
                redBeadQu.push({ i, j });
            else if (board[i][j] == BLUE_BEAD)
                blueBeadQu.push({ i, j });
            else if (board[i][j] == HOLE)
                holePosition = { i, j };
        }
    }

    moveCountQu.push(0);
    while(!moveCountQu.empty()) {
        position redPosition = redBeadQu.front();
        position bluePosition = blueBeadQu.front();
        int curCount = moveCountQu.front() + 1;
        if (curCount > 10)
            break;
        
        for(int curDirection = 0; curDirection <= 3; curDirection++) {
            if (isBeadMovable(redPosition, bluePosition, (direction)curDirection) ||
                isBeadMovable(bluePosition, redPosition, (direction)curDirection)) {
                
                std::pair<char, position> fstBead, secBead;
                getFstAndSecBead(redPosition, bluePosition, &fstBead, &secBead, (direction)curDirection);
            
                while(isBeadMovable(fstBead.second, secBead.second, (direction)curDirection)) {
                    moveBead(&fstBead.second, (direction)curDirection);
                    if (fstBead.second == holePosition) {
                        fstBead.second = HOLE_IN;
                        break;
                    }
                }
                while(isBeadMovable(secBead.second, fstBead.second, (direction)curDirection)) {
                    moveBead(&secBead.second, (direction)curDirection);
                    if (secBead.second == holePosition) {
                        secBead.second = HOLE_IN;
                        break;
                    }
                }
                
                if ((fstBead.first == RED_BEAD && fstBead.second == HOLE_IN && secBead.second != HOLE_IN) ||
                    (secBead.first == RED_BEAD && secBead.second == HOLE_IN && fstBead.second != HOLE_IN)) {
                    std::cout << curCount << std::endl;
                    return 0;
                }
                
                if ((fstBead.first == BLUE_BEAD && fstBead.second == HOLE_IN) ||
                    (secBead.first == BLUE_BEAD && secBead.second == HOLE_IN)) {
                    continue;
                }
                
                if (fstBead.first == RED_BEAD) {
                    redBeadQu.push(fstBead.second);
                    blueBeadQu.push(secBead.second);
                }
                else {
                    redBeadQu.push(secBead.second);
                    blueBeadQu.push(fstBead.second);
                }
                
                moveCountQu.push(curCount);
            }
        }
        
        redBeadQu.pop(); blueBeadQu.pop(); moveCountQu.pop();
    }
    
    std::cout << -1 << std::endl;
    return 0;
}
