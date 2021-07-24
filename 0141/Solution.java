import java.util.HashSet;
import java.util.Set;

public class Solution {
    Set<ListNode> dict = new HashSet<>();

    public boolean hasCycle(ListNode head) {
        if(head == null) {
            return false;
        }

        ListNode p = head;
        ListNode q = head.next;
        while(p!=q && q!= null && q.next != null) {
            p = p.next;
            q = q.next.next;
        }

        return q == p;
    }
}