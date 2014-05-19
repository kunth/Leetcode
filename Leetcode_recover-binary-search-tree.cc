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
