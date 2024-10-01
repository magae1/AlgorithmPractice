#include <iostream>
#include <string>

using namespace std;


int get_num(string& input, int idx) {
    string chunk;
    if (input[idx] == '+' || input[idx] == '-') {
        chunk += input[idx];
        idx++;
    }

    while (idx < input.size() && input[idx] != '+' && input[idx] != '-') {
        chunk += input[idx];
        idx++;
    }
    return stoi(chunk);
}

int main() {
    string input;
    cin >> input;

    int sum = get_num(input, 0);
    bool is_minus = false;
    for (int i = 1; i < input.size(); i++) {
        if (input[i] == '+') {
            if (is_minus) {
                sum -= get_num(input, i);
            } else {
                sum += get_num(input, i);
            }
        } else if (input[i] == '-') {
            sum += get_num(input, i);
            is_minus = true;
        }
    }

    cout << sum << endl;
    return 0;
}