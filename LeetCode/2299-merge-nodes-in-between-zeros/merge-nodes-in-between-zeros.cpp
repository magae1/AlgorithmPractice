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
    ListNode* mergeNodes(ListNode* head) { 
        ListNode* merged_node = head;
        ListNode* cur_node = head->next;
        while(cur_node != nullptr) {
            if (cur_node->val == 0) {
                if (cur_node->next == nullptr) {
                    merged_node->next = nullptr;
                    break;
                }
                merged_node->next = cur_node;
                merged_node = cur_node;
            } else {
                merged_node->val += cur_node->val;
            }
            cur_node = cur_node->next;
        }
        
        return head;
    }
};