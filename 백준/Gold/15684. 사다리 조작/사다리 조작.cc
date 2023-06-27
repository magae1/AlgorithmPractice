/*
 15684-사다리 조작
 */
#include <iostream>
#include <cmath>

const int MAX_ADDITIONAL_ROW_LINE = 3;
const int MAX_H = 30;
const int MAX_N = 10;

int addedLine[MAX_H+1][MAX_N+1];

bool checkCondition(int H, int N) {
    for (int i = 1; i <= N; i++) {
        int currentN = i;
        for (int j = 1; j <= H; j++) {
            if (addedLine[j][currentN] > 0)
                currentN = addedLine[j][currentN];
        }
        if (currentN != i)
            return false;
    }

    return true;
}

void func(int addedLineCount, int curH, int curN, int H, int N, int* addedCount) {
    
    if (addedLineCount > MAX_ADDITIONAL_ROW_LINE)
        return;
    
    if (checkCondition(H, N)) {
        if (*addedCount == -1) {
            *addedCount = addedLineCount;
        }
        else {
            *addedCount = std::min(*addedCount, addedLineCount);
        }
    }
    
    for (; curN < N; curN++) {
        for (; curH <= H; curH++) {
            if (addedLine[curH][curN] == 0 && addedLine[curH][curN+1] == 0) {
                addedLine[curH][curN] = curN+1;
                addedLine[curH][curN+1] = curN;
                func(addedLineCount+1, curH, curN, H, N, addedCount);
                addedLine[curH][curN] = 0;
                addedLine[curH][curN+1] = 0;
            }
        }
        curH = 1;
    }
}


int main() {
    int N, M, H;
    std::cin >> N >> M >> H;
    
    for (int i = 0; i < M; i++) {
        int tmpH, tmpN;
        std::cin >> tmpH >> tmpN;
        addedLine[tmpH][tmpN] = tmpN+1;
        addedLine[tmpH][tmpN+1] = tmpN;
    }
    
    int addedCount = -1;
    func(0, 1, 1, H, N, &addedCount);

    std::cout << addedCount << std::endl;
    return 0;
}
