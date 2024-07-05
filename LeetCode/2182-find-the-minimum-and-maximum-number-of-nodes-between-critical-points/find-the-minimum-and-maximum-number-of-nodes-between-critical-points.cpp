/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result{INT_MAX, INT_MIN};

        int cur_idx = 0, prev_val = head->val, prev_diff = 0;
        vector<int> critical_points;
        head = head->next;
        while (head != nullptr) {
            int cur_diff = head->val - prev_val;
            if ((prev_diff < 0 && cur_diff > 0) ||
                prev_diff > 0 && cur_diff < 0) {
                critical_points.push_back(cur_idx);
            }

            prev_diff = cur_diff;
            prev_val = head->val;
            head = head->next;
            cur_idx += 1;
        }

        if (critical_points.size() < 2) {
            vector<int> v{-1, -1};
            return v;
        }

        result[1] = critical_points.back() - critical_points.front();
        for (int i = 0; i < critical_points.size() - 1; i++) {
            int distance = critical_points[i + 1] - critical_points[i];
            result[0] = min(result[0], distance);
            if (distance <= 1)
                break;
        }

        return result;
    }
};