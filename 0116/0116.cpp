/*
// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        queue<Node *> q1;
        q1.push(root);
        int level = 1;
        while (!q1.empty())
        {
            for (int i = 0; i < level; i++)
            {
                Node *p = q1.front();
                q1.pop();
                if (i == level - 1)
                {
                    p->next = NULL;
                }
                else
                {
                    p->next = q1.front();
                }
                if (p->left != NULL)
                {
                    q1.push(p->left);
                    q1.push(p->right);
                }
            }
            level = level * 2;
        }
        return root;
    }
};