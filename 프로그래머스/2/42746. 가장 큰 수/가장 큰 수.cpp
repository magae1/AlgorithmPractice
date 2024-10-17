#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

string solution(vector<int> numbers) {
    int length = numbers.size();
    vector<string> num_strs(length);
    
    for (int i = 0; i < length; i++) {
        num_strs[i] = to_string(numbers[i]);
    }
    
    auto sorting = [](string l, string r) {
        return l + r > r + l;
    };
    
    sort(num_strs.begin(), num_strs.end(), sorting);
    
    string answer = "";
    for (string s : num_strs) {
        answer += s;
    }
    
    if (answer[0] == '0') return "0";
    
    return answer;
}