#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *last = head, *prev = head;
        for (int i = 0; i < n; i++) {
            last = last->next;
        }
        // delete the head point
        if (last == NULL) return head->next;
        while (last->next != NULL) {
            last = last->next;
            prev = prev->next;
        }
        // delete prev->next
        if (prev->next->next != NULL)
            prev->next = prev->next->next;
        else
            prev->next = NULL;

        return head;
    }
};