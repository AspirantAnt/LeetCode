#include <iostream>
#include <vector>
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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        queue<TreeNode *> q1;
        q1.push(root);
        int level = 0;
        while (!q1.empty())
        {
            int len = q1.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode *p = q1.front();
                q1.pop();
                if (p->left != nullptr)
                {
                    q1.push(p->left);
                }
                if (p->right != nullptr)
                {
                    q1.push(p->right);
                }
            }
            level++;
        }
        return level;
    }
};