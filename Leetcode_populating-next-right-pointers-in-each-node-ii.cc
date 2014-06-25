class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        TreeLinkNode *p = root, *last = NULL, *nxt = NULL;
        while(p)
        {
            if(p->left)
            {
                if(!last)
                    last = p->left;
                else
                    last = last->next = p->left;
                if(!nxt)
                    nxt = p->left;
            }
            if(p->right)
            {
                if(!last)
                    last = p->right;
                else
                    last = last->next = p->right;
                if(!nxt)
                    nxt = p->right;
            }
            p = p->next;
        }
        connect(nxt);
    }
};
