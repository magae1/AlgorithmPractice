#define MAX_BOX_SIZE 1000
#include <iostream>
#include <queue>

using namespace std;

int boxes[MAX_BOX_SIZE][MAX_BOX_SIZE];
queue<pair<int, int>> tomatoq;

bool isTomatoRipable (pair<int, int> target, int N, int M) {
    if (target.first < N && target.first >= 0 && target.second < M && target.second >= 0) {
        if (boxes[target.first][target.second] == 0) {
            return true;
        }
    }
    return false;
}
pair<int, int> getNearTomato (pair<int, int> origin, int dir) {
    int resultfst = origin.first;
    int resultsec = origin.second;
    
    switch(dir) {
        case 0:
            resultfst -= 1;
            break;
        case 1:
            resultfst += 1;
            break;
        case 2:
            resultsec += 1;
            break;
        case 3:
            resultsec -= 1;
            break;
        default:
            break;
    }
    
    pair<int, int> result = { resultfst, resultsec };
    return result;
}

int main() {
    int M, N;
    int totalNumofTomato = 0;
    int totalNumofRipeTomato = 0;
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> boxes[i][j];
            if (boxes[i][j] == 0) {
                totalNumofTomato++;
            } else if (boxes[i][j] == 1) {
                totalNumofTomato++;
                totalNumofRipeTomato++;
                tomatoq.push({i, j});
            }
        }
    }
    
    pair<int, int> origintomato = { -1, -1 };
    while(!tomatoq.empty()) {
        origintomato = tomatoq.front();
        for (int i = 0; i < 4; i++) {
            pair<int, int> neartomato = getNearTomato(origintomato, i);
            if (isTomatoRipable(neartomato, N, M)) {
                boxes[neartomato.first][neartomato.second] = boxes[origintomato.first][origintomato.second] + 1;
                tomatoq.push(neartomato);
                totalNumofRipeTomato++;
            }
        }
        tomatoq.pop();
    }
    if (totalNumofTomato != totalNumofRipeTomato) {
        cout << -1 << endl;
    } else {
        cout << boxes[origintomato.first][origintomato.second] - 1 << endl;
    }
    return 0;
}
