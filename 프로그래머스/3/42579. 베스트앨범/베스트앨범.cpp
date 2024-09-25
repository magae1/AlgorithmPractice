#include <string>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, deque<int>> song_map;
    map<string, int> genre_map;
    
    for (int i = 0; i < genres.size(); i++) {
        string genre = genres[i];
        
        if (auto iter = genre_map.find(genre); iter != genre_map.end()) {
            iter->second += plays[i];
        } else {
            genre_map.insert({genre, plays[i]});
        }
        
        if (auto iter = song_map.find(genre); iter != song_map.end()) {
            deque<int>& dq = iter->second;
            int front = dq.front();
            int back = dq.back();
            
            if (dq.size() < 2) {
                if (plays[front] < plays[i]) {
                    dq.push_front(i);
                } else {
                    dq.push_back(i);   
                }
                continue;
            }
            
            if (plays[front] < plays[i]) {
                dq.push_front(i);
                dq.pop_back();
            } else if (plays[back] < plays[i]) {
                dq.pop_back();
                dq.push_back(i);
            }
        } else {
            song_map.insert({genre, {i}});
        }
    } // end for
    
    vector<pair<string,int>> sorted_genres;
    for (auto m_iter = genre_map.begin(); m_iter != genre_map.end(); m_iter++) {
        sorted_genres.push_back({m_iter->first, m_iter->second});
    }
    struct {
        bool operator()(pair<string, int> a, pair<string, int> b) const { 
            return a.second > b.second; 
        }
    } customLess;
    sort(sorted_genres.begin(), sorted_genres.end(), customLess);
    
    vector<int> answer;
    for (pair<string, int> g : sorted_genres) {
        deque<int> dq = song_map[g.first];
        while (!dq.empty()) {
            answer.push_back(dq.front());
            dq.pop_front();
        }
    }
    return answer;
}