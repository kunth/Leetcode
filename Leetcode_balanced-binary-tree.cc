/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
    int my_max(int a, int b)
    {
        return a>=b ? a : b;
    }

    int getHeight(TreeNode*p)
    {
        if(p)
        {
            if(p->left && !p->right)
            {
                return 1+getHeight(p->left);
            }
            else if(p->right && !p->left)
            {
                return 1+getHeight(p->right);
            }
            else if(p->left && p->right)
            {
                return 1+my_max(getHeight(p->left), getHeight(p->right));
            }
            return 1;
        }
        return 0;
    }

    bool preorder(TreeNode*p)
    {
        if(p)
        {
            int llen = getHeight(p->left), rlen = getHeight(p->right);
            if(llen-rlen>1 || rlen-llen>1)
            {
                return false;
            }
            return preorder(p->left) && preorder(p->right);
        }
        return true;
    }

    bool isBalanced(TreeNode *root) {
        return preorder(root);
    }
};