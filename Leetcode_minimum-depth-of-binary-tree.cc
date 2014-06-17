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

//SECOND TRIAL
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(!root)
            return 0;
        queue<TreeNode*>treeq;
        queue<int>depthq;
        treeq.push(root);
        depthq.push(1);
        TreeNode* cur = NULL;
        int depth = 0;
        while(!treeq.empty())
        {
            cur = treeq.front();
            depth = depthq.front();
            treeq.pop();
            depthq.pop();
            if(!cur->left && !cur->right)
                return depth;
            if(cur->left)
            {
                treeq.push(cur->left);
                depthq.push(1+depth);
            }
            if(cur->right)
            {
                treeq.push(cur->right);
                depthq.push(1+depth);
            }
        }
    }
};
