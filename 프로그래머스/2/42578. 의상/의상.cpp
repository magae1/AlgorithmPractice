#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, set<string>> cloth_map;
    
    for (vector<string> cloth: clothes) {
        string name = cloth[0], category = cloth[1];
        
        if (auto iter = cloth_map.find(category); iter != cloth_map.end()) {
            iter->second.insert(name);
        } else {
            cloth_map.insert({category, {name}});
        }
    }
    
    int answer = 1;
    for (auto map_iter = cloth_map.begin(); map_iter != cloth_map.end(); map_iter++) {
        answer *= (map_iter->second.size() + 1);
    }
    return answer - 1;
}