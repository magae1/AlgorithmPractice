/*
 12886 - 돌 그룹
 */
#include <iostream>
#include <array>
#include <stack>
#include <algorithm>
#include <tuple>
using namespace std;

bool flag[1501][1501];

int main() {
    short total = 0;
    array<short, 3> rock;
    for (int i = 0; i < 3; i++) {
        cin >> rock[i];
        total += rock[i];
    }
    if (total % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    sort(rock.begin(), rock.end());
    
    stack<array<short, 3>> stk;
    stk.push(rock);
    while(!stk.empty()) {
        auto curArr = stk.top();
        stk.pop();
        while(true) {
            if (curArr[0] == curArr[1] && curArr[1] == curArr[2]) {
                cout << 1 << endl;
                return 0;
            }
            
            if (curArr[0] < curArr[1]) {
                auto newArr = curArr;
                newArr[1] -= newArr[0];
                newArr[0] += newArr[0];
                if (newArr[0] > newArr[1])
                    swap(newArr[0], newArr[1]);
                
                if (!flag[newArr[0]][newArr[1]]) {
                    flag[newArr[0]][newArr[1]] = true;
                    sort(newArr.begin(), newArr.end());
                    stk.push(newArr);
                    curArr = newArr;
                    continue;
                }
            }
            
            if (curArr[0] < curArr[2]) {
                auto newArr = curArr;
                newArr[2] -= newArr[0];
                newArr[0] += newArr[0];
                if (newArr[0] > newArr[2])
                    swap(newArr[0], newArr[2]);
                
                if (!flag[newArr[0]][newArr[2]]) {
                    flag[newArr[0]][newArr[2]] = true;
                    sort(newArr.begin(), newArr.end());
                    stk.push(newArr);
                    curArr = newArr;
                    continue;
                }
            }
            if (curArr[1] < curArr[2]) {
                auto newArr = curArr;
                newArr[2] -= newArr[1];
                newArr[1] += newArr[1];
                if (newArr[1] > newArr[2])
                    swap(newArr[1], newArr[2]);
                                
                if (!flag[newArr[1]][newArr[2]]) {
                    flag[newArr[1]][newArr[2]] = true;
                    sort(newArr.begin(), newArr.end());
                    stk.push(newArr);
                    curArr = newArr;
                    continue;
                }
            }
            break;
        }
    }
    cout << 0 << endl;
    return 0;
}
