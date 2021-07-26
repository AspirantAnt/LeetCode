class Solution {
    public ListNode insertionSortList(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode node = head;
        head = new ListNode();
        head.next = node;
        ListNode p = node.next;
        node.next = null;
        ListNode lastNode = node;

        while (p != null) {
            if (lastNode.val < p.val) {
                ListNode tmp = p;
                p = p.next;
                lastNode.next = tmp;
                tmp.next = null;
                lastNode = lastNode.next;

            } else {
                node = head;
                while (node.next != null && p.val > node.next.val) {
                    node = node.next;
                }

                ListNode tmp = p;
                p = p.next;
                tmp.next = node.next;
                node.next = tmp;
            }

        }
        return head.next;
    }
}