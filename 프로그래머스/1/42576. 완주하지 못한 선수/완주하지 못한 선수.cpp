#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> participant_map;
    
    for (string p : participant) {
        if (auto iter = participant_map.find(p); iter != participant_map.end()) {
            iter->second += 1;
        } else {
            participant_map.insert({p, 1});
        }
    }
    for (string c: completion) {
        if (auto iter = participant_map.find(c); iter != participant_map.end()) {
            if (iter->second == 1) {
                participant_map.erase(iter);
            }
            iter->second -= 1;
        }
    }
    
    return participant_map.begin()->first;
}