
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        Node *pre_level = root;
        while (pre_level->left != NULL)
        {
            Node *p = pre_level->left;
            p->next = pre_level->right;
            p = p->next;
            Node *tmp_pre_level = pre_level->next;
            while (tmp_pre_level != NULL)
            {
                p->next = tmp_pre_level->left;
                p = p->next;
                p->next = tmp_pre_level->right;
                tmp_pre_level = tmp_pre_level->next;
                p = p->next;
            }
            pre_level = pre_level->left;
        }
        return root;
    }
};