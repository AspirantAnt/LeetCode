#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        {
            return true;
        }
        TreeNode *cp_root = root;
        queue<TreeNode *> q1, q2;
        while (!q1.empty() || root != nullptr)
        {
            if ((cp_root == nullptr && root != nullptr) || (cp_root != nullptr && root == nullptr))
            {
                return false;
            }
            else if (cp_root == nullptr && root == nullptr)
            {
                root = q1.front();
                q1.pop();
                cp_root = q2.front();
                q2.pop();
            }
            else if (cp_root->val != root->val)
            {
                return false;
            }
            else
            {
                q1.push(root->left);
                q1.push(root->right);
                q2.push(cp_root->right);
                q2.push(cp_root->left);
                root = q1.front();
                q1.pop();
                cp_root = q2.front();
                q2.pop();
            }
        }
        return true;
    }
};