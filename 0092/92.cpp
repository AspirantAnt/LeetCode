#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        // 添加头指针，方便操作
        ListNode *real_head = new ListNode(0);
        real_head->next = head;
        // p为m-1的节点指针
        ListNode *p = real_head;
        for (int i = 1; i < m; i++)
        {
            p = p->next;
        }
        // 操作的指针
        ListNode *cur = p->next->next;
        // 原先m的指针
        ListNode *last = p->next;

        int index = m + 1;
        while (cur != NULL && index <= n)
        {
            ListNode *first = p->next;
            // 将cur 插入到p后面
            p->next = cur;
            ListNode *next_cur = cur->next;
            cur->next = first;
            last->next = next_cur;
            cur = next_cur;
            index++;
        }
        return real_head->next;
    }
};