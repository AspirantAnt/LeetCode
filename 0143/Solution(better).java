class Solution {
    public void reorderList(ListNode head) {
        if (head == null) {
            return;
        }
        ListNode p = head;
        ListNode q = head;
        while (q != null && q.next != null) {
            p = p.next;
            q = q.next.next;
        }
        q = new ListNode(0);
        while (p.next != null) {
            ListNode tmp = p.next;
            p.next = tmp.next;
            tmp.next = q.next;
            q.next = tmp;
        }

        p = head;
        while (p != null && q.next != null) {
            ListNode tmp = q.next;
            q.next = tmp.next;
            tmp.next = p.next;
            p.next = tmp;
            p = tmp.next;
        }
    }
}