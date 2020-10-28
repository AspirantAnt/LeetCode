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
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }
        else
        {
            if (root->left != nullptr && root->right != nullptr)
            {
                int l, r;
                l = minDepth(root->left);
                r = minDepth(root->right);
                return (l < r ? l : r) + 1;
            }
            else
            {
                if (root->left != nullptr)
                {
                    return minDepth(root->left) + 1;
                }
                else
                {
                    return minDepth(root->right) + 1;
                }
            }
        }
    }
};