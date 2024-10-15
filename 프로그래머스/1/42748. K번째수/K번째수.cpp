#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (vector<int> command : commands) {
        int start = command[0] - 1;
        int end = command[1] - 1;
        int idx = command[2] - 1;
        
        int size = end - start + 1;
        vector<int> slice(size);
        for (int i = 0; i < size; i++) {
            slice[i] = array[i + start];
        }
        sort(slice.begin(), slice.end());
        answer.push_back(slice[idx]);
    }
    return answer;
}