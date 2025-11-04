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
    public ListNode modifiedList(int[] nums, ListNode head) {
        Set<Integer> numSet = Arrays.stream(nums).boxed().collect(Collectors.toSet());

        ListNode prev = null;
        ListNode current = head;
        while(current != null) {
            if (numSet.contains(current.val)) {
                if (prev == null) {
                    head = current.next;
                } else {
                    prev.next = current.next;
                }
                current = current.next;
            } else {
                prev = current;
                current = current.next;   
            }
        }

        return head;
    }
}