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
    bool addPath(TreeNode *root, int num, int sum)
    {
        if (root->val + num == sum && root->left == nullptr && root->right == nullptr)
        {
            return true;
        }
        bool flag = false;
        if (root->left != nullptr)
        {
            flag = addPath(root->left, root->val + num, sum);
        }
        if (flag)
        {
            return true;
        }
        if (root->right != nullptr)
        {
            flag = addPath(root->right, root->val + num, sum);
        }
        return flag;
    }
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->val == sum && root->left == nullptr && root->right == nullptr)
        {
            return true;
        }
        bool flag = false;
        if (root->left != nullptr)
        {
            flag = addPath(root->left, root->val, sum);
        }
        if (flag)
        {
            return true;
        }
        if (root->right != nullptr)
        {
            flag = addPath(root->right, root->val, sum);
        }
        return flag;
    }
};