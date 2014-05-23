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
    void dfs(TreeNode*p, int& allsum, int pathsum)
    {
        pathsum = pathsum*10+p->val;
        if(!p->left && !p->right)
        {
            allsum+=pathsum;
            return;
        }
        if(p->left)
        {
            dfs(p->left, allsum, pathsum);
        }
        if(p->right)
        {
            dfs(p->right, allsum, pathsum);
        }
    }
    int sumNumbers(TreeNode *root) {
        if(!root)
            return 0;
        int ret = 0, pathsum = 0;
        dfs(root, ret, pathsum);
        return ret;
    }
};
