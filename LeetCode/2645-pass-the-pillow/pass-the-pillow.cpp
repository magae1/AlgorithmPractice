class Solution {
public:
    int passThePillow(int n, int time) {
        int size = (n - 1) * 2;
        int idx = time % size;
        if (idx <= n - 1) {
            return idx + 1;
        } else {
            return n - (idx - (n - 1));
        }
    }
};