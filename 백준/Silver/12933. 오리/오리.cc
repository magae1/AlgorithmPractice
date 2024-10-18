#include <iostream>
#include <string>
#include <vector>

using namespace std;

string SOUND = "quack";

int main() {
    string input;
    cin >> input;

    int length_of_sound = SOUND.length();
    vector<vector<char> > ducks;
    for (char c : input) {
        bool is_inserted = false;
        for (vector<char>& duck : ducks) {
            int next_sound_idx = duck.size() % length_of_sound;
            if (SOUND[next_sound_idx] == c) {
                is_inserted = true;
                duck.push_back(c);
                break;
            }
        }
        
        if (is_inserted) continue;

        if (c == SOUND[0]) {
            vector<char> new_duck;
            new_duck.push_back(c);
            ducks.push_back(new_duck);
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    for (vector<char>& duck : ducks) {
        if (duck.size() % 5 != 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ducks.size() << endl;
    return 0;
}