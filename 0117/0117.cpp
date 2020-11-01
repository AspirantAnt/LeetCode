class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *pre_level = root;
        // 前面一层
        while (pre_level != NULL)
        {
            // 找到下一层第一个节点
            while (pre_level != NULL && pre_level->left == NULL && pre_level->right == NULL)
            {
                pre_level = pre_level->next;
            }
            // 如果下一层没有节点
            if (pre_level == NULL)
            {
                break;
            }
            // 有节点
            Node *p = NULL, *first = NULL;
            if (pre_level->left != NULL)
            {
                p = pre_level->left;
                first = p;
                if (pre_level->right != NULL)
                {
                    p->next = pre_level->right;
                    p = p->next;
                }
            }
            else
            {
                p = pre_level->right;
                first = p;
            }
            pre_level = pre_level->next;

            // 循环查找下一个节点
            while (pre_level != NULL)
            {
                // 查找下一个有子节点的节点
                while (pre_level != NULL && pre_level->left == NULL && pre_level->right == NULL)
                {
                    pre_level = pre_level->next;
                }
                if (pre_level == NULL)
                {
                    break;
                }
                if (pre_level->left != NULL)
                {
                    p->next = pre_level->left;
                    p = p->next;
                }
                if (pre_level->right != NULL)
                {
                    p->next = pre_level->right;
                    p = p->next;
                }
                pre_level = pre_level->next;
            }
            if (first == NULL)
            {
                break;
            }
            else
            {
                pre_level = first;
            }
        }
        return root;
    }
};