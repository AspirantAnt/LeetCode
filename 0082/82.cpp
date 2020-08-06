#include "./myheaders.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL)
            return head;
        ListNode *p, *pre = new ListNode(0);
        pre->next = head;
        ListNode *result = pre;
        p = head;

        while (p->next != NULL && p != NULL) {
            if (p->next->val == p->val) { // 需要删
                while (p != NULL && p->next != NULL && p->val == p->next->val) {
                    if (p->next->next == NULL)
                        p->next = NULL;
                    else {
                        ListNode *tmp = p->next->next;
                        p->next = tmp;
                    }
                }
                if (p->next == NULL)
                    pre->next = NULL;
                else {
                    ListNode *tmp = p->next;
                    pre->next = tmp;
                    p = pre->next;
                }
            } else { // 不需要删
                pre = p;
                p = p->next;
            }
        }
        return result->next;
    }
};