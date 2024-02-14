/*
 9019 - DSLR
 */
#include <iostream>
#include <cmath>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <array>
using namespace std;

short node[10000][4];

const char CH[] = {
  'D', 'S', 'L', 'R'
};
void D(short* a) {
    *a *= 2;
    *a %= 10000;
}
void S(short* a) {
    if (*a == 0)
        *a = 9999;
    else
        *a -= 1;
}
void L(short* a) {
    deque<char> deq;
    for (int i = 3; i >= 0; i--) {
        char ch = *a / pow(10, i);
        deq.push_back(ch);
        *a -= ch * pow(10, i);
    }
    deq.push_back(deq.front());
    deq.pop_front();
    for (int i = 3; i >= 0; i--) {
        *a += deq.front() * pow(10, i);
        deq.pop_front();
    }
}
void R(short* a) {
    deque<char> deq;
    for (int i = 3; i >= 0; i--) {
        char ch = *a / pow(10, i);
        deq.push_back(ch);
        *a -= ch * pow(10, i);
    }
    
    deq.push_front(deq.back());
    deq.pop_back();
    
    for (int i = 3; i >= 0; i--) {
        *a += deq.front() * pow(10, i);
        deq.pop_front();
    }
}
short instructions(short input, int i) {
    switch(i) {
        case 0:
            D(&input);
            break;
        case 1:
            S(&input);
            break;
        case 2:
            L(&input);
            break;
        case 3:
            R(&input);
            break;
    }
    return input;
}

int main() {
    array<bool, 10000> flag;
    short N;
    cin >> N;
    
    while (N--) {
        flag.fill(false);
        short start, end;
        cin >> start >> end;

        string result = "";
        queue<pair<short, string>> qu;
        qu.push({start, ""});
        flag[start] = true;
        while(!qu.empty()) {
            short curShort = qu.front().first;
            string curStr = qu.front().second;

            if (curShort == end) {
                result = curStr;
                break;
            }

            for (int i = 0; i < 4; i++) {
                short nextShort;
                if (node[curShort][i] > 0) {
                    nextShort = node[curShort][i];
                }
                else {
                    nextShort = instructions(curShort, i);
                    node[curShort][i] = nextShort;
                }
                                
                if (!flag[nextShort]) {
                    flag[nextShort] = true;
                    qu.push({
                        nextShort, curStr + CH[i]
                    });
                }
            }
            qu.pop();
        }
        
        cout << result << endl;
    }
    return 0;
}
