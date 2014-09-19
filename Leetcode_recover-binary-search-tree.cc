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
    TreeNode*lastNode = NULL, *sw1 = NULL, *sw2 = NULL;
    void in_order_tra(TreeNode* root)
    {
        if(root->left)
            in_order_tra(root->left);
        if(lastNode)
        {
            if(lastNode->val > root->val)
            {
                if(!sw1)
                {
                    sw1 = lastNode;
                    sw2 = root;
                }
                else
                {
                    sw2 = root;
                    return;
                }
            }
        }
        lastNode = root;
        if(root->right)
            in_order_tra(root->right);
    }
    void recoverTree(TreeNode *root) {
        if(!root)
            return;
        in_order_tra(root);
        if(sw1 && sw2)
            swap(sw1->val, sw2->val);
    }
};

//Second trial, almost the same
class Solution {
private:
    TreeNode*p1, *p2, *last;
    void inOrder(TreeNode *root) {
        if(root->left)
            inOrder(root->left);
        if(last) {
            if(last->val > root->val) {
                if(!p1) {
                    p1 = last;
                    p2 = root;
                } else {
                    p2 = root;
                    return;
                }
            }
        }
        last = root;
        if(root->right)
            inOrder(root->right);
    }
public:
    void recoverTree(TreeNode *root) {
        if(!root)
            return;
        last = p1 = p2 = NULL;
        inOrder(root);
        if(p1 && p2)
            swap(p1->val, p2->val);
    }
};
