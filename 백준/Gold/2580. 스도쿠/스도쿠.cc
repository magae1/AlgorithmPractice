/*
 2580 - 스도쿠
 */
#include <iostream>
#include <vector>
using namespace std;

short board[9][9];
bool rowFlag[9][10];
bool colFlag[9][10];
bool boxFlag[3][3][10];
vector<pair<short, short>> blanks;

void func(int index, bool* done) {
    if (index == blanks.size()) {
        *done = true;
        return;
    }
    
    auto chosen = blanks[index];
    for (int i = 1; i <= 9; i++) {
        if (!rowFlag[chosen.first][i] && !colFlag[chosen.second][i] &&
            !boxFlag[chosen.first/3][chosen.second/3][i]) {
            board[chosen.first][chosen.second] = i;
            rowFlag[chosen.first][i] = true;
            colFlag[chosen.second][i] = true;
            boxFlag[chosen.first/3][chosen.second/3][i] = true;
            func(index + 1, done);
            if (!(*done)) {
                board[chosen.first][chosen.second] = 0;
                rowFlag[chosen.first][i] = false;
                colFlag[chosen.second][i] = false;
                boxFlag[chosen.first/3][chosen.second/3][i] = false;
            }
        }
    }
}

int main() {
    for (short i = 0; i < 9; i++) {
        for (short j = 0; j < 9; j++) {
            short input;
            cin >> input;
            board[i][j] = input;
            if (input == 0)
                blanks.push_back({i, j});
            else {
                rowFlag[i][input] = true;
                colFlag[j][input] = true;
                boxFlag[i/3][j/3][input] = true;
            }
        }
    }
    
    bool done = false;
    func(0, &done);
    
    cout << endl;
    for (short i = 0; i < 9; i++) {
        for (short j = 0; j < 9; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
