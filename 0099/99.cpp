#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        TreeNode *p = root;
        if (p == nullptr)
            return;
        stack<TreeNode *> s1;
        TreeNode *swap1 = nullptr, *swap2 = nullptr, *pre = nullptr;
        // 获取中序
        while (!s1.empty() || p != nullptr)
        {

            // left
            while (p != nullptr)
            {
                s1.push(p);
                p = p->left;
            }
            // mid
            p = s1.top();
            s1.pop();
            if (pre != nullptr && pre->val > p->val)
            {
                swap1 = p;
                if (swap2 == nullptr)
                {
                    swap2 = pre;
                }
                else
                {
                    // 也许只找到一次，所以不能在这里进行交换
                    break;
                }
            }
            // right
            pre = p;
            p = p->right;
        }
        int tmp = swap1->val;
        swap1->val = swap2->val;
        swap2->val = tmp;
    }
};