/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
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