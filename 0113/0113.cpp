/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> addSum(TreeNode *root, int sum, vector<int> prePath, int num)
    {
        vector<vector<int>> result;
        if (root == nullptr)
        {
            return result;
        }
        vector<int> now_path = prePath;
        now_path.emplace_back(root->val);
        if (root->val + num == sum && root->left == nullptr && root->right == nullptr)
        {
            result.emplace_back(now_path);
            return result;
        }
        vector<vector<int>> left_result = addSum(root->left, sum, now_path, root->val + num);
        vector<vector<int>> right_result = addSum(root->right, sum, now_path, root->val + num);
        for (auto item : left_result)
        {
            result.emplace_back(item);
        }
        for (auto item : right_result)
        {
            result.emplace_back(item);
        }
        return result;
    }
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        return addSum(root, sum, vector<int>(), 0);
    }
};