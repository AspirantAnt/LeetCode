#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *result;
        ListNode *p = result;
        if (lists.size() == 0) return result;
        int len = lists.size();
        int empty = 0;
        for (int i = 0; i < len; i++) {
            if (lists[i] == NULL) empty++;
        }
        while (empty != len) {
            int minIndex;
            for (minIndex = 0; minIndex < len && lists[minIndex] == NULL;
                 minIndex++) {
            }
            int minNum = lists[minIndex]->val;
            for (int i = minIndex + 1; i < len; i++) {
                if (lists[i] == NULL) continue;
                if (lists[i]->val < minNum) {
                    minNum = lists[i]->val;
                    minIndex = i;
                }
            }
            p->next = new ListNode(minNum);
            p = p->next;
            lists[minIndex] = lists[minIndex]->next;
            if (lists[minIndex] == NULL) empty++;
        }
        return result->next;
    }
};