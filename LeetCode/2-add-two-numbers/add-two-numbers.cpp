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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        bool isUp = false;

        if (l1->val + l2->val >= 10) {
            head->val = (l1->val + l2->val) % 10;
            isUp = true;
        } else {
            head->val = l1->val + l2->val;
        }

        ListNode* cur_head = head;
        l1 = l1->next;  
        l2 = l2->next;

        while (isUp || l1 || l2) {
            ListNode* next_node = new ListNode();
            if (l1) {
                next_node->val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                next_node->val += l2->val;
                l2 = l2->next;
            }
            if (isUp) {
                next_node->val += 1;
            }

            if (next_node->val >= 10) {
                isUp = true;
                next_node->val -= 10;
            } else {
                isUp = false;
            }

            cur_head->next = next_node;
            cur_head = cur_head->next;
        }
        return head;
    }
};