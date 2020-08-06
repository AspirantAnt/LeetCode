#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
  public:
    ListNode *swapPairs(ListNode *head) {
        if (head->next == NULL || head == NULL) return head;
        ListNode *pre = head, *last = head->next;
        while (last != NULL) {
            int tmp = pre->val;
            pre->val = last->val;
            last->val = tmp;
            if (last->next == NULL) return head;
            pre = pre->next->next;
            last = last->next->next;
        }
        return head;
    }
};