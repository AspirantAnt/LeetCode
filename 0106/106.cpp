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

    TreeNode *myBuildTree(vector<int> &in, vector<int> &post, int in_start, int in_end, int post_start, int post_end)
    {
        // 只有一个节点
        if (post_start == post_end)
        {
            return new TreeNode(post[post_end]);
        }
        else if (post_start > post_end)
        {
            return nullptr;
        }
        TreeNode *mid = new TreeNode(post[post_end]);
        int n = this->hash_index[mid->val];
        // 左边长度
        int left_len = n - in_start;
        mid->left = myBuildTree(in, post, in_start, n - 1, post_start, post_start + left_len - 1);
        mid->right = myBuildTree(in, post, n + 1, in_end, post_start + left_len, post_end - 1);
        return mid;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int len = postorder.size();
        if (len == 0)
        {
            return nullptr;
        }
        // init hash list
        for (int i = 0; i < len; i++)
        {
            this->hash_index[inorder[i]] = i;
        }
        int index = postorder[len - 1];
        return myBuildTree(inorder, postorder, 0, len - 1, 0, len - 1);
    }
};