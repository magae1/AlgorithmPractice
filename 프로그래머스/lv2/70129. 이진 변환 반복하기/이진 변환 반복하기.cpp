#include <string>
#include <vector>
#include <stack>
using namespace std;

string getNextString(int size) {
    string result = "";
    stack <char> stk;
    while(size > 0) {
        char ch = ' ';
        switch(size % 2) {
            case 1:
                ch = '1';
                break;
            case 0:
                ch = '0';
                break;
        }
        
        stk.push(ch);
        size /= 2;
    }
    while(!stk.empty()) {
        result += stk.top();
        stk.pop();
    }
    return result;
}

vector<int> solution(string s) {
    int numOfTransform = 0;
    int numOfRemovedZero = 0;
    
    while(s.size() > 1) {
        string tmp = "";
        for (char ch : s) {
            if (ch == '1')
                tmp += ch;
            else if (ch == '0')
                numOfRemovedZero++;
        }
        
        int tmpSize = tmp.size();
        s = getNextString(tmpSize);
        numOfTransform++;
    }
    
    vector<int> answer(2);
    answer[0] = numOfTransform;
    answer[1] = numOfRemovedZero;
    return answer;
}