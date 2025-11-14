/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode headNext = head.next;
        head.next = headNext.next;
        headNext.next = head;
        head = headNext;

        ListNode prev = head.next;
        ListNode current = head.next.next;
        while(current != null) {
            ListNode next = current.next;
            if (next == null) {
                break;
            }

            prev.next = current.next;
            current.next = next.next;
            next.next = current;
            prev = prev.next.next;
            current = current.next;
        }
        return head;
    }
}