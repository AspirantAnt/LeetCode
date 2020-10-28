/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int getLen(ListNode *head)
    {
        int len = 0;
        while (head != nullptr)
        {
            len++;
            head = head->next;
        }
        return len;
    }
    TreeNode *buildTree(ListNode *&head, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        TreeNode *p = new TreeNode();
        int mid = (left + right + 1) / 2;
        p->left = buildTree(head, left, mid - 1);
        p->val = head->val;
        head = head->next;
        p->right = buildTree(head, mid + 1, right);
        return p;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        int len = getLen(head);
        return buildTree(head, 0, len - 1);
    }
};