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

//SECOND TRIAL, bfs
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(!root)
            return 0;
        queue<TreeNode*>treeq;
        treeq.push(root);
        TreeNode* cur = NULL;
        int ans = 0;
        while(!treeq.empty())
        {
            int sz = treeq.size();
            ++ans;
            while(sz--)
            {
                cur = treeq.front();
                treeq.pop();
                if(cur->left)
                    treeq.push(cur->left);
                if(cur->right)
                    treeq.push(cur->right);
            }
        }
        return ans;
    }
};
