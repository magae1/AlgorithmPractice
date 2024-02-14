#include <iostream>
#include <queue>
#include <climits>
using namespace std;

const int MAX_SIZE = 8;

enum BLOCK_INDEX {
    SAFE = 0,
    WALL = 1,
    VIRUS = 2
};

struct block {
    int original;
    int temp;
};

block blocks[MAX_SIZE][MAX_SIZE];

//감염시킬 수 있는 블럭 반환. 없다면 -1 -1.
pair<int, int> infectableBlock(int N, int M, pair<int, int> originPosition, int i) {
    switch(i) {
        case 0:
            originPosition = { originPosition.first-1, originPosition.second };
            break;
        case 1:
            originPosition = { originPosition.first, originPosition.second-1 };
            break;
        case 2:
            originPosition = { originPosition.first+1, originPosition.second };
            break;
        case 3:
            originPosition = { originPosition.first, originPosition.second+1 };
            break;
        default:
            break;
    }
    
    if (originPosition.first >= 0 && originPosition.first < N
        && originPosition.second >= 0 && originPosition.second < M) {
        return originPosition;
    }
    return pair<int, int> { -1, -1 };
}
bool isBuildableBlock(int N, int M, int row, int col) {
    if (blocks[row][col].temp == SAFE)
        return true;
    else
        return false;
}

int main() {
    
    //N은 세로 크기, M은 가로 크기
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> originVirusPositions;
    vector<pair<int, int>> builablePositions;
    int safeBlockCount = 0;
    queue<pair<int, int>> qu;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> blocks[i][j].original;
            switch(blocks[i][j].original) {
                case VIRUS:
                    originVirusPositions.push_back(pair<int, int> { i, j });
                case WALL:
                    break;
                case SAFE:
                    builablePositions.push_back(pair<int, int> { i, j });
                    ++safeBlockCount;
                default:
                    break;
            }
        }
    }
//    cout << safeBlockCount << endl;
    
    int smallestInfectedBlockCount = INT_MAX;
    
    for (auto fstPositionIter = builablePositions.begin(); fstPositionIter != builablePositions.end(); fstPositionIter++) {
        for (auto secPositionIter = fstPositionIter+1; secPositionIter != builablePositions.end(); secPositionIter++) {
            for (auto thrdPositionIter = secPositionIter+1; thrdPositionIter != builablePositions.end(); thrdPositionIter++) {
                
                //초기화
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++)
                        blocks[i][j].temp = blocks[i][j].original;
                }
                for (pair<int, int> virusPosition : originVirusPositions)
                    qu.push(virusPosition);
                
                //벽 세우기
                blocks[(*fstPositionIter).first][(*fstPositionIter).second].temp = WALL;
                blocks[(*secPositionIter).first][(*secPositionIter).second].temp = WALL;
                blocks[(*thrdPositionIter).first][(*thrdPositionIter).second].temp = WALL;
                
//                cout << (*fstPositionIter).first << "," << (*fstPositionIter).second << " " <<
//                (*secPositionIter).first << "," << (*secPositionIter).second << " " <<
//                (*thrdPositionIter).first << "," << (*thrdPositionIter).second << endl;
                
                
                int tempInfectedBlockCount = 3;
                //감염
                while(!qu.empty()) {
                    pair<int,int> frontQ = qu.front();
                    
                    for (int i = 0; i < 4; i++) {
                        pair<int, int> nextPosition = infectableBlock(N, M, frontQ, i);
                        if (nextPosition.first != -1
                                && blocks[nextPosition.first][nextPosition.second].temp == SAFE) {
                            blocks[nextPosition.first][nextPosition.second].temp = VIRUS;
                            tempInfectedBlockCount++;
                            qu.push(nextPosition);
                        }
                    }//for..END
                    qu.pop();
                }//while..END
                
                smallestInfectedBlockCount = min(smallestInfectedBlockCount, tempInfectedBlockCount);
//                cout << tempInfectedBlockCount << ", " << smallestInfectedBlockCount << endl;
            }
        }
    }
    
    int result = safeBlockCount - smallestInfectedBlockCount;
    cout << result << endl;
    return 0;
}

