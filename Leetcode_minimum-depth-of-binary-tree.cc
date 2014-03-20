//http://oj.leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode *root) {
        if(!root)
        {
            return 0;
        }
        int height = 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            ++height;
            int size = q.size();
            while(size--)
            {
                TreeNode* pnode = q.front();
                q.pop();
                if(!pnode->left && !pnode->right)
                {
                    return height;
                }
                if(pnode->left)
                {
                    q.push(pnode->left);
                }
                if(pnode->right)
                {
                    q.push(pnode->right);
                }
            }
        }
    }
};
