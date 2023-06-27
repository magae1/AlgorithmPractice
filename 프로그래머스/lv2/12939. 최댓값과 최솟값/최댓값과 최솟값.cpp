#include <string>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

string solution(string s) {    
    int highest = INT_MIN;
    int lowest = INT_MAX;
    
    string tmpStr = "";
    for (char ch : s) {
        if (ch == ' ' || ch == '\n') {
            int num = stoi(tmpStr);
            tmpStr.clear();
            highest = max(highest, num);
            lowest = min(lowest, num);            
        }
        else {
            tmpStr += ch;
        }
    }
    highest = max(highest, stoi(tmpStr));
    lowest = min(lowest, stoi(tmpStr));            
        
    string answer = "";
    answer += to_string(lowest);
    answer += ' ';
    answer += to_string(highest);
    return answer;
}