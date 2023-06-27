/*
 16197 - 두 동전
 */
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

enum {
    COIN = 'o',
    WALL = '#',
    EMPTY = '.'
};
enum {
    MOVE = 'M',
    FALL = 'F',
    STOP = 'S'
};

typedef pair<int, int> position;

position getMovement(int direction) {
    switch(direction) {
        case 0:
            return {-1, 0};
        case 1:
            return {0, 1};
        case 2:
            return {1, 0};
        case 3:
            return {0, -1};
        default:
            return {0, 0};
    }
}

void sortCoinsByDirection(vector<position>& coins, int direction) {
    auto fstCoin = coins.begin();
    auto secCoin = coins.begin()+1;
    
    switch(direction) {
        case 0:
            if (fstCoin->first > secCoin->first) {
                swap(*fstCoin, *secCoin);
            }
            break;
        case 1:
            if (fstCoin->second < secCoin->second) {
                swap(*fstCoin, *secCoin);
            }
            break;
        case 2:
            if (fstCoin->first < secCoin->first) {
                swap(*fstCoin, *secCoin);
            }
            break;
        case 3:
            if (fstCoin->second > secCoin->second) {
                swap(*fstCoin, *secCoin);
            }
            break;
    }
}

char getTypeOfMove(position coin, vector<vector<char>>& board, int direction, int N, int M) {
    position movement = getMovement(direction);
    coin.first += movement.first;
    coin.second += movement.second;
    
    if (coin.first >= N || coin.first < 0 ||
        coin.second >= M || coin.second < 0)
        return FALL;
    else if (board[coin.first][coin.second] == WALL)
        return STOP;
    else
        return MOVE;
}

void moveCoin(position& coin, vector<vector<char>>& board, int direction) {
    position movement = getMovement(direction);
    board[coin.first][coin.second] = EMPTY;
    coin.first += movement.first;
    coin.second += movement.second;
    board[coin.first][coin.second] = COIN;
}
void fallCoin(position& coin, vector<vector<char>>& board, int direction) {
    position movement = getMovement(direction);
    board[coin.first][coin.second] = EMPTY;
    coin.first += movement.first;
    coin.second += movement.second;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<char>> board(N, vector<char>(M));
    vector<position> coins;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        
        int j = 0;
        for (auto chIt = str.begin(); chIt != str.end(); chIt++) {
            if (*chIt == COIN) {
                coins.push_back({i,j});
            }
            
            board[i][j] = *chIt;
            j++;
        }
    }

    queue<vector<position>> qu;
    queue<int> count;
    qu.push(coins);
    count.push(0);
    int result = -1;
    while(!qu.empty()) {
        auto quFront = qu.front();
        auto curCount = count.front();
        
        if (result > 0 || curCount >= 10)
            break;
        
        for (int i = 0; i < 4; i++) {
            vector<position> positionVector = quFront;
            short fallCount = 0;
            bool isMoved = false;
            sortCoinsByDirection(positionVector, i);
            for (auto coinIter = positionVector.begin(); coinIter != positionVector.end(); coinIter++) {
                switch(getTypeOfMove(*coinIter, board, i, N, M)) {
                    case MOVE:
                        moveCoin(*coinIter, board, i);
                        isMoved = true;
                        break;
                    case FALL:
                        fallCoin(*coinIter, board, i);
                        isMoved = true;
                        fallCount++;
                        break;
                }
            }
            if (isMoved) {
                switch(fallCount) {
                    case 0:
                        qu.push(positionVector);
                        count.push(curCount + 1);
                        break;
                    case 1:
                        result = curCount + 1;
                        break;
                }
            }
        }
        qu.pop();
        count.pop();
    }
    cout << result << endl;
    return 0;
}
