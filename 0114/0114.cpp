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
    void flatten(TreeNode *root)
    {
        TreeNode *p = root;
        stack<TreeNode *> s1;
        TreeNode *last = root;
        while (p != nullptr || !s1.empty())
        {
            while (p != nullptr)
            {
                last = p;
                s1.push(p);
                p = p->left;
            }
            p = s1.top();
            s1.pop();
            // 没有右子树
            while (p->right == nullptr && !s1.empty())
            {
                p = s1.top();
                s1.pop();
            }
            if (p->right == nullptr && s1.empty())
            {
                break;
            }
            last->left = p->right;
            p->right = nullptr;
            p = last->left;
        }
        p = root;
        while (p != nullptr)
        {
            p->right = p->left;
            p->left = nullptr;
            p = p->right;
        }
    }
};