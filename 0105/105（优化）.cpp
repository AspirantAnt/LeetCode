#include <iostream>
#include <vector>
#include <unordered_map>
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
    unordered_map<int, int> hash_index;

    TreeNode *myBuildTree(vector<int> &pre, vector<int> &in, int pre_start, int pre_end, int in_start, int in_end)
    {
        // 只有一个节点
        if (pre_start == pre_end)
        {
            return new TreeNode(pre[pre_start]);
        }
        else if (pre_start > pre_end)
        {
            return nullptr;
        }
        TreeNode *mid = new TreeNode(pre[pre_start]);
        int n = this->hash_index[pre[pre_start]];
        // 左边长度
        int left_len = n - in_start;
        mid->left = myBuildTree(pre, in, pre_start + 1, pre_start + left_len, in_start, n - 1);
        mid->right = myBuildTree(pre, in, pre_start + left_len + 1, pre_end, n + 1, in_end);
        return mid;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int len = preorder.size();
        if (len == 0)
        {
            return nullptr;
        }
        // init hash list
        for (int i = 0; i < len; i++)
        {
            this->hash_index[inorder[i]] = i;
        }
        TreeNode *mid = new TreeNode(preorder[0]);
        if (len == 1)
        {
            return mid;
        }
        int n = this->hash_index[preorder[0]];
        mid->left = myBuildTree(preorder, inorder, 1, n, 0, n - 1);
        mid->right = myBuildTree(preorder, inorder, n + 1, len - 1, n + 1, len - 1);
        return mid;
    }
};