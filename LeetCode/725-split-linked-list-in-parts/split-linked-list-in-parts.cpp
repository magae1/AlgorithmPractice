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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;
        int length = 0;
        ListNode* cur_node = head;

        while (cur_node) {
            length += 1;
            cur_node = cur_node->next;
        }

        int div = length / k;
        int reminder = length % k;

        ListNode* next_node = nullptr;
        cur_node = head;
        int size = 0;
        for (int i = 0; i < k; i++) {
            result.push_back(cur_node);
            if (cur_node == nullptr) {
                continue;
            }

            size = div;
            if (reminder > 0) {
                size += 1;
                reminder -= 1;
            }
            while (size > 1) {
                cur_node = cur_node->next;
                size -= 1;
            }
            next_node = cur_node->next;
            cur_node->next = nullptr;
            cur_node = next_node;
        }
        return result;
    }
};