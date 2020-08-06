#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *pre = head, *last = head;
        for (int i = 0; i < k - 1; i++) {
            if (last->next == NULL || last == NULL) return head;
            last = last->next;
        }
        while (last != NULL) {
            int tmp = pre->val;
            pre->val = last->val;
            last->val = tmp;
            myReverse(pre->next, k - 2);
            for (int i = 0; i < k; i++) {
                last = last->next;
                if (last == NULL) return head;
                pre = pre->next;
            }
        }
        myReverse(head, k);
        return head;
    }
    void myReverse(ListNode *head, int k) {
        if (k < 2) return;
        int i;
        ListNode *pre = head, *last = head;
        for (i = 0; i < k - 1; i++) {
            if (last == NULL || last->next == NULL) return;
            last = last->next;
        }
        int tmp = pre->val;
        pre->val = last->val;
        last->val = tmp;
        myReverse(pre->next, k - 2);
        return;
    }
};