#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

bool flag[10];
vector<char> signs;
vector<string> strs;
string str;
bool isLegalInput(int front, int back, char sign) {
    if (sign == '>')
        return (front > back);
    else if (sign == '<')
        return (front < back);
    else
        return false;
}

void func(int index, int k) {
    if (index > k) {
        strs.push_back(str);
        return;
    }
    
    for (int i = 0; i < 10; i++) {
        if (str.empty() || isLegalInput(str.back()-'0', i, signs[index-1])) {
            if (!flag[i]) {
                flag[i] = true;
                str.push_back(i+'0');
                func(index+1, k);
                str.pop_back();
                flag[i] = false;
            }
        }
    }
}


int main() {
    int k;
    cin >> k;
    
    for(int i = 0; i < k; i++) {
        char c;
        cin >> c;
        signs.push_back(c);
    }
    
    func(0, k);
    
//    for (auto st : strs) {
//        cout << st << endl;
//    }
    
    cout << strs.back() << endl << strs.front() << endl;
    return 0;
}
