#include <string>
#include <cctype>
using namespace std;

string solution(string s) {
    string answer = "";
    bool makeItUpper = true;
    
    for (char ch : s) {
        if (ch >= 65 && ch <= 90) {
            if (!makeItUpper) {
                ch += 32;
            }
        }
        else if (ch >= 97 && ch <= 122) {
            if (makeItUpper) {
                ch -= 32;
            }
        }
        
        if (ch == ' ')
            makeItUpper = true;
        else
            makeItUpper = false;
        
        answer += ch;
    }
    return answer;
}