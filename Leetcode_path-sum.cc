//http://oj.leetcode.com/problems/path-sum/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 bool dfs(TreeNode*p, int value)
 {
     if(p->val == value && !(p->left) && !(p->right))
     {
         return true;
     }
     else if(p->left && dfs(p->left, value - p->val))
     {
         return true;
     }
     else if(p->right && dfs(p->right, value - p->val))
     {
         return true;
     }
     return false;
 }
 
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root)
            return false;
        return dfs(root, sum);
    }
};
