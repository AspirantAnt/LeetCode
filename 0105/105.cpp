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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int len = preorder.size();
        if (len == 0)
        {
            return nullptr;
        }
        int midNum = preorder[0];
        TreeNode *mid = new TreeNode(midNum);
        if (len == 1)
        {
            return mid;
        }
        int index = 0;
        vector<int> pre_left_vec;
        vector<int> pre_right_vec;
        vector<int> in_left_vec;
        vector<int> in_right_vec;
        for (index = 0; index < len && inorder[index] != midNum; index++)
        {
            in_left_vec.push_back(inorder[index]);
            pre_left_vec.push_back(preorder[index + 1]);
        }
        int left_len = index;
        for (int i = left_len + 1; i < len; i++)
        {
            pre_right_vec.push_back(preorder[i]);
        }
        for (int i = index + 1; i < len; i++)
        {
            in_right_vec.push_back(inorder[i]);
        }
        mid->left = buildTree(pre_left_vec, in_left_vec);
        mid->right = buildTree(pre_right_vec, in_right_vec);
        return mid;
    }
};