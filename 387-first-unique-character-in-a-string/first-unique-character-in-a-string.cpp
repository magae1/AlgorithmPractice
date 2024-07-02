class Solution {
public:
    int firstUniqChar(string s) {
        map<char, pair<int, int>> char_map;
        for (int i = 0; i < s.size(); i++) {
            if (auto search_key = char_map.find(s[i]); search_key != char_map.end()) {
                search_key->second.second++;
            } else {
                char_map.insert({s[i], {i, 1}});
            }
        }

        int idx = 100000;
        for (auto iter = char_map.begin(); iter != char_map.end(); iter++) {
            if (iter->second.second <= 1) {
                idx = min(idx, iter->second.first);
            }
        }
        return idx == 100000 ? -1 : idx;
    }
};