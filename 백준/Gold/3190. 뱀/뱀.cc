#include <iostream>
#include <vector>
#include <deque>
using namespace std;

enum direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
};
const char LEFT = 'L';
const char RIGHT = 'D';
const pair<int, int> initPosition = {1,1};
const direction initDirection = EAST;

struct {
    pair<int, int> position = initPosition;
    direction dir = initDirection;
}snakeHead;

void changeDirectionByChange(direction* dir, char change) {
    if (change == LEFT)
        *dir = (int)*dir -1 < 0 ? WEST : (direction)((int)*dir -1);
    else if (change == RIGHT)
        *dir = (direction)(((int)*dir +1) % 4);
}

void moveSnakeHead() {
    switch(snakeHead.dir) {
        case NORTH:
            snakeHead.position = { snakeHead.position.first-1, snakeHead.position.second };
            break;
        case EAST:
            snakeHead.position = { snakeHead.position.first, snakeHead.position.second+1 };
            break;
        case SOUTH:
            snakeHead.position = { snakeHead.position.first+1, snakeHead.position.second };
            break;
        case WEST:
            snakeHead.position = { snakeHead.position.first, snakeHead.position.second-1 };
            break;
    }
}

int main() {
    int N, K, L;
    cin >> N;

    cin >> K;
    vector<pair<int, int>> applePositions(K);
    for (int i = 0; i < K; i++)
        cin >> applePositions[i].first >> applePositions[i].second;

    cin >> L;
    vector<pair<int, char>> directionChanges(L);
    for (int i = 0; i < L; i++)
        cin >> directionChanges[i].first >> directionChanges[i].second;

    deque<pair<int,int>> snake;
    int moveCount = 0;
    for (auto dirChangeIterator = directionChanges.begin(); ;) {
        /*
//        뱀 이동과정을 출력
        cout << moveCount << endl;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                bool print = false;
                if (isSamePosition(snakeHead.position, {i, j})) {
                    cout << "@";
                    print = true;
                }

                if (!print) {
                    for (auto appleIterator = applePositions.begin(); appleIterator != applePositions.end(); appleIterator++) {
                        if (isSamePosition(*appleIterator, {i, j})) {
                            cout << "A";
                            print = true;
                            break;
                        }
                    }
                }

                if (!print) {
                    for (auto snakeIterator = snake.begin(); snakeIterator != snake.end(); snakeIterator++) {
                        if (isSamePosition(*snakeIterator, {i, j})) {
                            cout << "O";
                            print = true;
                            break;
                        }
                    }
                }

                if (!print) {
                    cout << "_";
                }
            }
            cout << endl;
        }
        cout << endl;
         */
        
        bool isSnakeDead = false;
        
//        방향변경정보에 따른 방향 변경
        if ((*dirChangeIterator).first == moveCount) {
            changeDirectionByChange(&snakeHead.dir, (*dirChangeIterator).second);
            dirChangeIterator++;
        }
        
//        뱀 머리 이동
        pair<int, int> ownHeadPosition = snakeHead.position;
        snake.push_front(ownHeadPosition);
        moveSnakeHead();
        moveCount++;
        
//        이동한 위치가 벽인지 확인
        if (snakeHead.position.first > N || snakeHead.position.first <= 0 ||
            snakeHead.position.second > N || snakeHead.position.second <= 0) {
            isSnakeDead = true;
        }
                    
//        이동한 위치가 자기자신의 몸인지 확인
        for (auto snakeBodyIterator = snake.begin(); snakeBodyIterator != snake.end(); snakeBodyIterator++) {
            if (*snakeBodyIterator == snakeHead.position) {
                isSnakeDead = true;
                break;
            }
        }
                
//        뱀이 죽었는지 확인
        if (isSnakeDead) {
            cout << moveCount << endl;
            return 0;
        }
        
//        이동한 칸에 사과가 있는지 확인
        bool eatApple = false;
        for (auto appleIterator = applePositions.begin(); appleIterator != applePositions.end(); appleIterator++) {
            if (*appleIterator == snakeHead.position) {
                eatApple = true;
                applePositions.erase(appleIterator);
                break;
            }
        }
        if (!eatApple)
            snake.pop_back();
    }//for..END
}//main..END
