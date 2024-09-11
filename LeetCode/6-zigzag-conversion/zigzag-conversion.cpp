class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        string result;
        int total = 2 * (numRows - 1);
        for (int r = 0; r < numRows && r < s.size(); r++) {
            int col = r;
            int offset = total - r * 2;
            vector<int> offsets = {offset == 0 ? total : offset,
                                   offset == total ? total : total - offset};
            for (int i = 0; col < s.size(); i++) {
                result += s[col];
                col += offsets[i % 2];
            }
        }
        return result;
    }
};