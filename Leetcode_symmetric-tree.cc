//http://oj.leetcode.com/problems/symmetric-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool is_sub_symm(TreeNode* p, TreeNode* q)
{
    if(p && q)
    {
        if(p->val == q->val && is_sub_symm(p->left, q->left))
        {
            return is_sub_symm(p->right, q->right);
        }
    }
    else if(!p && !q)
    {
        return true;
    }
    return false;
}
 
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(!root)
        {
            return true;
        }
        return is_sub_symm(root->left, root->right);
    }
};
