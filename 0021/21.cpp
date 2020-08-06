#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *p = new ListNode(1);
        ListNode *result = p;
        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL) {
                p->next = l2;
                l2 = l2->next;
            } else if (l2 == NULL) {
                p->next = l1;
                l1 = l1->next;
            } else if (l1->val >= l2->val) {
                p->next = l2;
                l2 = l2->next;
            } else if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            p = p->next;
        }
        return result->next;
    }
};