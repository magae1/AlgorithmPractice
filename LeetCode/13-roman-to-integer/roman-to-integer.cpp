class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        char c = ' ', p = ' ';
        for (int i = s.length() - 1; i >= 0; i--) {
            c = s[i];
            if (c == 'I') {
                if (p == 'V' || p == 'X') {
                    result -= 1;
                } else {
                    result += 1;
                }
            } else if (c == 'V') {
                result += 5;
            } else if (c == 'X') {
                if (p == 'L' || p == 'C') {
                    result -= 10;
                } else {
                    result += 10;
                }
            } else if (c == 'L') {
                result += 50;
            } else if (c == 'C') {
                if (p == 'D' || p == 'M') {
                    result -= 100;
                } else {
                    result += 100;
                }
            } else if (c == 'D') {
                result += 500;
            } else if (c == 'M') {
                result += 1000;
            }
            p = c;
        }
        return result;
    }
};