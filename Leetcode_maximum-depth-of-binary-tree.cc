//http://oj.leetcode.com/problems/maximum-depth-of-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int max_depth = 0;
void dfs(TreeNode* node, int depth)
{
    if(node)
    {
        ++depth;
        if(node->left) 
        {
            dfs(node->left, depth);
        }
        if(node->right)
        {
            dfs(node->right, depth);
        }
    }
    max_depth = max_depth > depth ? max_depth : depth;
}
 
class Solution {
public:
    int maxDepth(TreeNode *root) {
        max_depth = 0;
        dfs(root, 0);
        return max_depth;
    }
};
