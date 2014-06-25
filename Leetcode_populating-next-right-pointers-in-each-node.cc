/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

//96ms, constant space
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root && root->left)
        {
            if(root->next)
                root->right->next = root->next->left;

            root->left->next = root->right;
            connect(root->left);
            connect(root->right);
        }
    }
};


//or the below one, 88ms, O(lgn) extra space
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root)
        {
            int levelsum = 1;
            TreeLinkNode* p = root, *pre = NULL, *cur = NULL;
            queue<TreeLinkNode*>q;
            q.push(p);
            while(!q.empty())
            {
                for(int i = 0; i<levelsum; ++i)
                {
                    cur = q.front();
                    if(cur->left)
                    {
                        q.push(cur->left);
                        q.push(cur->right);
                    }
                    if(pre)
                        pre->next = cur;
                    pre = cur;
                    q.pop();
                }
                cur->next = pre = NULL;
                levelsum*=2;
            }
        }
    }
};

//SECOND TRIAL
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        if(root->left)
        {
            root->left->next = root->right;
            if(root->next)
                root->right->next = root->next->left;

            connect(root->left);
            connect(root->right);
        }
    }
};
