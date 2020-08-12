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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
        {
            return result;
        }
        queue<TreeNode *> q1;
        q1.push(root);
        while (!q1.empty())
        {
            result.insert(result.begin(), vector<int>());
            int len = q1.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode *p = q1.front();
                q1.pop();
                result.front().emplace_back(p->val);
                if (p->left != nullptr)
                {
                    q1.push(p->left);
                }
                if (p->right != nullptr)
                {
                    q1.push(p->right);
                }
            }
        }
        return result;
    }
};