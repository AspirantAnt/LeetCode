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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
        {
            return result;
        }
        queue<TreeNode *> q1;
        q1.push(root);
        bool flag = true;
        while (!q1.empty())
        {
            result.push_back(vector<int>());
            int len = q1.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode *p = q1.front();
                q1.pop();
                if (flag)
                {
                    result.back().emplace_back(p->val);
                }
                else
                {
                    result.back().insert(result.back().begin(), p->val);
                }
                if (p->left != nullptr)
                {
                    q1.push(p->left);
                }
                if (p->right != nullptr)
                {
                    q1.push(p->right);
                }
            }
            flag = !flag;
        }
        return result;
    }
};