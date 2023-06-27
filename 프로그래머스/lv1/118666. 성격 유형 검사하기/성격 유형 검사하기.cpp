#include <string>
#include <vector>

using namespace std;

const char TYPE[4][2] = {'R', 'T',
                        'C', 'F',
                        'J', 'M',
                        'A', 'N'};
pair<char, int> getTypeAndScore(string sur, int choice) {
    pair<char, int> result = { ' ', 0 };
    choice -= 4;
    if (choice > 0) {
        result.first = *(sur.begin() + 1);
        result.second = choice;
    }
    else if (choice < 0) {
        result.first = *(sur.begin());
        result.second = -choice;
    }
    return result;
}

void recordScore(vector<int>& scores, pair<char, int>typeboard) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            if (typeboard.first == TYPE[i][j]) {
                if (j == 0) {
                    scores[i] += (-typeboard.second);
                }
                else {
                    scores[i] += typeboard.second;
                }
            }
        }
    }
}


string solution(vector<string> survey, vector<int> choices) {
    vector<int> scores(4, 0);
    
    for (int i = 0; i < survey.size(); i++) {
        string sur = survey[i];
        int choice = choices[i];
        pair<char, int> typeBoard = getTypeAndScore(sur, choice);
        recordScore(scores, typeBoard);
    }
    
    
    
    string answer = "";
    for (int i = 0; i < 4; i++) {
        if (scores[i] > 0) {
            answer += TYPE[i][1];
        }
        else {
         answer += TYPE[i][0];   
        }
    }
    return answer;
}