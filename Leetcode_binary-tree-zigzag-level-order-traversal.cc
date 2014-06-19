//http://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> >res;
        bool flag = true;
        if(!root)
        {
            return res;
        }
        else
        {
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty())
            {
                int size = q.size();
                vector<int> vec;
                while(vec.size() < size)
                {
                    TreeNode* root = q.front();
                    q.pop();
                    vec.push_back(root->val);

                    if(root->left)
                    {
                        q.push(root->left);
                    }
                    if(root->right)
                    {
                        q.push(root->right);
                    }
                }
                flag = !flag;
                if(flag)
                {
                    reverse(vec.begin(), vec.end());
                }
                res.push_back(vec);
            }
        }
        return res;
    }
};

//SECOND TRAIL
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> >ans;
        if(!root)
            return ans;
        queue<TreeNode*>treeq;
        treeq.push(root);
        TreeNode* cur = NULL;
        bool flag = true;
        while(!treeq.empty())
        {
            int sz = (int)treeq.size();
            vector<int>vec;
            while(sz--)
            {
                cur = treeq.front();
                treeq.pop();
                vec.push_back(cur->val);
                if(cur->left)
                    treeq.push(cur->left);
                if(cur->right)
                    treeq.push(cur->right);
            }
            if(!flag)
                reverse(vec.begin(), vec.end());
                
            ans.push_back(vec);
            flag = !flag;
        }
        return ans;
    }
};
