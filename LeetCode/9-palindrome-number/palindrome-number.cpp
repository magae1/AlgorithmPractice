class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (x < 10) {
            return true;
        }

        int left_most = 1000000000;
        int right_most = 1;
        while (left_most > 1) {
            int m = x / left_most;
            if (m > 0) {
                break;
            }
            left_most = left_most / 10;
        }

        while (left_most >= right_most) {
            cout << x / left_most % 10 << ", " << x / right_most % 10 << endl;
            if (x / left_most % 10 != x / right_most % 10) {
                return false;
            }
            left_most = left_most / 10;
            right_most = right_most * 10;
        }
        return true;
    }
};