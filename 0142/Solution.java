public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head == null ) {
            return null;
        }
        ListNode slow = head;
        ListNode fast = head;
        while(fast != null) {
            slow = slow.next;
            if(fast.next != null) {
                fast = fast.next.next;
            } else {
                return null;
            }
            if(fast == slow) {
                ListNode p = head;
                while(p != slow) {
                    p = p.next;
                    slow = slow.next;
                }
                return p;
            }
        }
        return null;
    }
}