#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (root == NULL)
        {
            return result;
        }
        stack<TreeNode *> s;
        while (root != NULL || !s.empty())
        {
            // left
            while (root != NULL)
            {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            result.push_back(root->val);
            // right
            root = root->right;
        }
        return result;
    }
};