/*
 14890 - 경사로
 */
#include <iostream>
#include <vector>
#include <stack>
const int MAX_N = 100;
int map[MAX_N][MAX_N];

void func(bool isRow, int startN, int N, int L, int* roadCount) {
    std::stack<std::pair<int,int>> stk;
    for (int i = 0; i < N; i++) {
        int pushingOne;
        if (isRow)
            pushingOne = map[startN][i];
        else
            pushingOne = map[i][startN];
        
        if (stk.empty())
            stk.push({ pushingOne, 0 });
        else {
            if (stk.top().first - pushingOne == 0) {
                stk.push({ pushingOne, --stk.top().second });
            }
            else if (stk.top().first - pushingOne == - 1) {
                if (stk.top().second + L > 1)
                    return;
                stk.push({ pushingOne, 0 });
            }
            else if (stk.top().first - pushingOne == 1) {
                if (stk.top().second > 1)
                    return;
                stk.push({ pushingOne, L });
            }
            else
                return;
        }
    }//for..END
    
    if (stk.top().second <= 1)
        (*roadCount)++;
}


int main() {
    int N, L;
    std::cin >> N >> L;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> map[i][j];
        }
    }
    
    int roadCount = 0;
    for (int i = 0; i < N; i++) {
        func(true, i, N, L, &roadCount);
        func(false, i, N, L, &roadCount);
//        std::cout << roadCount << std::endl;
    }
    std::cout << roadCount << std::endl;
    return 0;
}
