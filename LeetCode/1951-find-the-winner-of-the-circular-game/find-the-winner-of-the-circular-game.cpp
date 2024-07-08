class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n <= 1) {
            return n;
        }

        struct Friend {
            int num;
            Friend* next_friend;
        };

        Friend* f = new Friend(1);
        Friend* head = f;
        for (int i = 2; i <= n; i++) {
            Friend* new_friend = new Friend(i);
            head->next_friend = new_friend;
            head = head->next_friend;
        }
        head->next_friend = f;
        
        Friend* prev_friend = head;
        Friend* cur_friend = f;
        while (n > 1) {
            for (int i = 1; i < k; i++) {
                prev_friend = cur_friend;
                cur_friend = cur_friend->next_friend;
            }
            prev_friend->next_friend = cur_friend->next_friend;
            delete cur_friend;
            cur_friend = prev_friend->next_friend;
            n--;
        }
        return cur_friend->num;
    }
};