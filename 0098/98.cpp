#include <iostream>
#include <vector>
#include <algorithm>
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
    bool isValidBST(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->left != NULL)
        {
            vector<int> left = searchTree(root->left);
            if (!left[0] || left[2] >= root->val)
            {
                return false;
            }
        }
        if (root->right != NULL)
        {
            vector<int> right = searchTree(root->right);
            if (!right[0] || right[1] <= root->val)
            {
                return false;
            }
        }
        return true;
    }
    // 返回一个数组
    // [0]这个节点是否符合二叉排序，0，不符合，1符合
    // [1] 子树最小值
    // [2] 子树最大值
    vector<int> searchTree(TreeNode *root)
    {
        vector<int> result = {1, root->val, root->val};
        // 得到左右子树是否符合和左右子树的最小值和最大值
        vector<int> left(3, 0);
        vector<int> right(3, 0);
        // 如果有左子树
        if (root->left != NULL)
        {
            left = searchTree(root->left);
            if (!left[0] || left[2] >= root->val)
            {
                result[0] = 0;
                return result;
            }
            result[1] = min(result[1], left[1]);
            result[2] = max(result[2], left[2]);
        }
        // 如果有右子树
        if (root->right != NULL)
        {
            right = searchTree(root->right);
            if (!right[0] || right[1] <= root->val)
            {
                result[0] = 0;
                return result;
            }
            result[1] = min(result[1], right[1]);
            result[2] = max(result[2], right[2]);
        }

        return result;
    }
};