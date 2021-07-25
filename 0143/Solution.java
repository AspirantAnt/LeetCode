import java.util.ArrayList;

class Solution {
    public void reorderList(ListNode head) {
        if (head == null || head.next == null) {
            return;
        }
        List<ListNode> list = new ArrayList<>();
        ListNode p = head;
        while (p != null) {
            list.add(p);
            p = p.next;
        }
        int len = list.size();
        p = head;
        for (int i = len - 1; i >= (len / 2 + 1) && p != null; i--) {
            list.get(i).next = p.next;
            p.next = list.get(i);
            p = p.next.next;
        }
        if (len / 2 == 0) {
            p = p.next;
        }
        p.next = null;

    }
}