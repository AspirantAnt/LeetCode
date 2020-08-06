#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *p = head;
        int len = 0;
        while (p != NULL) {
            len++;
            p = p->next;
        }
        if (len == 0 || len == 1) return head;
        k = k % len;
        if (k == 0) return head;
        ListNode *result = p = head;
        int position = k;
        while (position++ < len - 1) { p = p->next; }
        result = p->next;
        p->next = NULL;
        ListNode *last = result;
        while (last->next != NULL) last = last->next;
        last->next = head;
        return result;
    }
};