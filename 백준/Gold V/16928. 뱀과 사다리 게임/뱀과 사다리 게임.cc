/*
 16928 - 뱀과 사다리 게임
 */
#include <iostream>
#include <queue>
#include <array>
#include <map>
#include <climits>
using namespace std;

const char LADDER = 'L';
const char SNAKE = 'S';
const char EMPTY = 'E';

int main() {
    array<char, 101> block;
    array<short, 101> count;
    block.fill(EMPTY);
    count.fill(SHRT_MAX);
    
    int N, M;
    cin >> N >> M;
    
    map<short, short> ladders;
    for (int i = 0; i < N; i++) {
        short start, end;
        cin >> start >> end;
        block[start] = LADDER;
        ladders[start] = end;
    }
    
    map<short, short> snakes;
    for (int i = 0; i < M; i++) {
        short start, end;
        cin >> start >> end;
        block[start] = SNAKE;
        snakes[start] = end;
    }
    
    short result = 0;
    queue<short> qu;
    qu.push(1);
    count[1] = 0;
    while(!qu.empty()) {
        short curBlock= qu.front();
        short curCount = count[curBlock];
        
        if (curBlock == 100) {
            result = curCount;
            break;
        }

        for (short i = 6; i >= 1; i--) {
            short movedBlock = curBlock + i;
            if (movedBlock <= 100 && count[movedBlock] > curCount) {
                count[movedBlock] = curCount + 1;
                if (block[movedBlock] == LADDER) {
                    movedBlock = ladders.find(movedBlock)->second;
                    count[movedBlock] = curCount + 1;
                }
                else if (block[movedBlock] == SNAKE) {
                    movedBlock = snakes.find(movedBlock)->second;
                    count[movedBlock] = curCount + 1;
                }
                qu.push(movedBlock);
            }
        }
        qu.pop();
    }
    
    cout << result << endl;
    return 0;
}
