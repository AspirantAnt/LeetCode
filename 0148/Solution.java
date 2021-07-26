class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null) {
            return null;
        }
        return sortList(head, null);
    }

    private ListNode sortList(ListNode head, ListNode tail) {
        if (head == null) {
            return null;
        } else if (head.next == tail) {
            head.next = null;
            return head;
        }
        ListNode slow = head;
        ListNode fast = head;
        while (fast != tail) {
            slow = slow.next;
            fast = fast.next;
            if (fast != tail) {
                fast = fast.next;
            }
        }
        return merge(sortList(head, slow), sortList(slow, tail));
    }

    private ListNode merge(ListNode list1, ListNode list2) {
        ListNode fakeNode = new ListNode(0);
        ListNode p = fakeNode;
        ListNode tmp1 = list1;
        ListNode tmp2 = list2;
        while (tmp1 != null && tmp2 != null) {
            if (tmp1.val < tmp2.val) {
                p.next = tmp1;
                tmp1 = tmp1.next;
            } else {
                p.next = tmp2;
                tmp2 = tmp2.next;
            }
            p = p.next;
        }

        if (tmp1 != null) {
            p.next = tmp1;
        } else if (tmp2 != null) {
            p.next = tmp2;
        }
        return fakeNode.next;
    }
}