#include "./myheaders.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        // 增加头结点
        ListNode p(0);
        p.next = head;
        head = &p;
        ListNode *point, *tmp = head;

        // 找到插入点
        while (tmp->next != NULL)
        {
            if (tmp->next->val >= x)
            {
                point = tmp;
                break;
            }
            tmp = tmp->next;
        }
        // 从插入点往后查找
        while (tmp->next != NULL)
        {
            if (tmp->next->val < x)
            {
                // 把节点删除，然后放到point后
                ListNode *del_point = tmp->next;
                tmp->next = del_point->next;
                del_point->next = point->next;
                point->next = del_point;
                point = point->next;
            }
            else
                tmp = tmp->next;
        }
        return head->next;
    }
};