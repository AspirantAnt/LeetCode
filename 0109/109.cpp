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
    TreeNode *getTree(vector<int> &nums, int start, int end)
    {
        if (end < start)
        {
            return NULL;
        }
        int mid = start + (end - start + 1) / 2;
        TreeNode *p = new TreeNode(nums[mid]);
        p->left = this->getTree(nums, start, mid - 1);
        p->right = this->getTree(nums, mid + 1, end);
        return p;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        vector<int> nums;
        while (head != nullptr)
        {
            nums.emplace_back(head->val);
            head = head->next;
        }
        int len = nums.size();
        if (len == 0)
        {
            return NULL;
        }
        TreeNode *result = new TreeNode(nums[len / 2]);
        result->left = this->getTree(nums, 0, len / 2 - 1);
        result->right = this->getTree(nums, len / 2 + 1, len - 1);
        return result;
    }
};