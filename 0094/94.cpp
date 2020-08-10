#include <iostream>
#include <vector>
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
        int mid = root->val;
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);
        for (int i = 0; i < left.size(); i++)
        {
            result.push_back(left[i]);
        }
        result.push_back(mid);
        for (int i = 0; i < right.size(); i++)
        {
            result.push_back(right[i]);
        }
        return result;
    }
};