//http://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> >res;
        if(!root)
        {
            return res;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> vec;
            while(size--)
            {
                TreeNode*p = q.front();
                vec.push_back(p->val);
                if(p->left)
                {
                    q.push(p->left);
                }
                if(p->right)
                {
                    q.push(p->right);
                }
                q.pop();
            }
            res.push_back(vec);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//SECOND TRIAL, almost the same
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> >ans;
        if(!root)
            return ans;
        queue<TreeNode*>treeq;
        treeq.push(root);
        TreeNode *cur = NULL;
        int sz = 0;
        while(!treeq.empty())
        {
            vector<int>v;
            sz = treeq.size();
            while(sz--)
            {
                cur = treeq.front();
                treeq.pop();
                v.push_back(cur->val);
                if(cur->left)
                    treeq.push(cur->left);
                if(cur->right)
                    treeq.push(cur->right);
            }
            ans.push_back(v);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
