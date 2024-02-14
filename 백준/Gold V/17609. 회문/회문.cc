#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <tuple>
using namespace std;


int main() {
    int N;
    cin >> N;
    
    vector<short> results;
    while(N--) {
        string str;
        cin >> str;
        
        short result = 0;
    
        stack<tuple<int, int>> stk;
        stk.push({0, str.size() - 1});
        while(!stk.empty()) {
            auto curIndex = stk.top();
            int frontIndex = get<0>(curIndex);
            int backIndex = get<1>(curIndex);
            stk.pop();
            
            while(frontIndex < backIndex) {
                if (str[frontIndex] == str[backIndex]) {
                    frontIndex++;
                    backIndex--;
                }
                else {
                    if (result == 0) {
                        stk.push({frontIndex, backIndex - 1});
                        frontIndex++;
                        result++;
                    }
                    else {
                        result++;
                        break;
                    }
                }
            }
            if (frontIndex >= backIndex)
                break;
        }

        if (result >= 3) {
            result = 2;
        }
        else if (result >= 1) {
            result = 1;
        }
        results.push_back(result);
    }
    
    for (short result : results) {
        cout << result << endl;
    }
    return 0;
}
